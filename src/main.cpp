#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <cassert>
#include <sstream>
#include "ReserveStation.h"
#include "RegisterStatus.h"
#include "Instruction.h"
#include "String.h"
#include "InstructionStatus.h"
#include "command.h"
#define pii pair<int, int> 

using namespace std;

//============================================= STATEMENT

#define EPS 1e-6
#define MAX_N 1000
#define LOAD_SIZE 3
#define ADD_SIZE 3
#define MUL_SIZE 2
#define DIV_SIZE 2
#define LOAD_TIME 2
#define ADD_TIME 2
#define MUL_TIME 10
#define DIV_TIME 40

const int REG_SIZE = 16;
const int MEM_SIZE = 128;

double reg[REG_SIZE * 2];
double mem[MEM_SIZE];

RegisterStatus Qi(REG_SIZE * 2);

vector< ReserveStation* > load(LOAD_SIZE);
vector< ReserveStation* > add(ADD_SIZE);
vector< ReserveStation* > mul(MUL_SIZE);
vector< ReserveStation* > divid(DIV_SIZE);
bool load_vis[LOAD_SIZE];
bool add_vis[ADD_SIZE];
bool mul_vis[MUL_SIZE];
bool div_vis[DIV_SIZE];

vector<Instruction> ins;

InstructionStatus ins_status;

vector<string> ins_status_strings;
vector<string> reserve_station_strings;
vector<string> reg_result_status_strings;

int cycle = 0, num = 0;
int tot_time = 0;

//============================================= TOMASULO

void updateQi(ReserveStation *r, double result) {
    if (r == nullptr) return;
    for (int i = 0; i < REG_SIZE; ++i) {
        if (Qi[i] == r) {
            reg[i] = result;
            Qi[i] = nullptr;
        }
    }
}

void updateQj(ReserveStation *r, double result) {
    if (r == nullptr) return;
    for (int i = 0; i < LOAD_SIZE; ++i) {
        if (load[i]->getQj() == r) {
            load[i]->setVj(result);
            load[i]->setQj(nullptr);
        }
    }
    for (int i = 0; i < ADD_SIZE; ++i) {
        if (add[i]->getQj() == r) {
            add[i]->setVj(result);
            add[i]->setQj(nullptr);
        }
    }
    for (int i = 0; i < MUL_SIZE; ++i) {
        if (mul[i]->getQj() == r) {
            mul[i]->setVj(result);
            mul[i]->setQj(nullptr);
        }
    }
    for (int i = 0; i < DIV_SIZE; ++i) {
        if (divid[i]->getQj() == r) {
            divid[i]->setVj(result);
            divid[i]->setQj(nullptr);
        }
    }
}

void updateQk(ReserveStation *r, double result) {
    if (r == nullptr) return;
    for (int i = 0; i < LOAD_SIZE; ++i) {
        if (load[i]->getQk() == r) {
            load[i]->setVk(result);
            load[i]->setQk(nullptr);
        }
    }
    for (int i = 0; i < ADD_SIZE; ++i) {
        if (add[i]->getQk() == r) {
            add[i]->setVk(result);
            add[i]->setQk(nullptr);
        }
    }
    for (int i = 0; i < MUL_SIZE; ++i) {
        if (mul[i]->getQk() == r) {
            mul[i]->setVk(result);
            mul[i]->setQk(nullptr);
        }
    }
    for (int i = 0; i < DIV_SIZE; ++i) {
        if (divid[i]->getQk() == r) {
            divid[i]->setVk(result);
            divid[i]->setQk(nullptr);
        }
    }
}

void updateQ(ReserveStation *r, double result) {
    updateQi(r, result);
    updateQj(r, result);
    updateQk(r, result);
}

void check_wb(int cycle) {
    for (int i = 0; i < LOAD_SIZE; ++i) {
        if (!(load[i]->isBusy())) continue;
        if (load[i]->getStatus() != writeback) continue;
        int t = load[i]->timeDec();
        if (t <= 0) {
            ins_status.reset(load[i]->getNum(), (int)(load[i]->getStatus()), cycle);
            double result = 0;
            load[i]->setAddress(load[i]->getVj() + load[i]->getAddress());
            if (load[i]->getOp() == "load") {
                result = mem[load[i]->getAddress()];
                updateQ(load[i], result);
            } else {    
                mem[load[i]->getAddress()] = load[i]->getVk();
            }
            load[i]->reset();
        }
    }
    for (int i = 0; i < ADD_SIZE; ++i) {
        if (!(add[i]->isBusy())) continue;
        if (add[i]->getStatus() != writeback) continue;
        int t = add[i]->timeDec();
        if (t <= 0) {
            ins_status.reset(add[i]->getNum(), (int)(add[i]->getStatus()), cycle);
            double result = 0;
            if (add[i]->getOp() == "add.d") {
                result = add[i]->getVj() + add[i]->getVk();
            } else {
                result = add[i]->getVj() - add[i]->getVk();
            }
            updateQ(add[i], result);
            add[i]->reset();
        }
    }
    for (int i = 0; i < MUL_SIZE; ++i) {
        if (!(mul[i]->isBusy())) continue;
        if (mul[i]->getStatus() != writeback) continue;
        int t = mul[i]->timeDec();
        if (t <= 0) {
            ins_status.reset(mul[i]->getNum(), (int)(mul[i]->getStatus()), cycle);
            double result = 0;
            result = mul[i]->getVj() * mul[i]->getVk();
            updateQ(mul[i], result);
            mul[i]->reset();
        }
    }
    for (int i = 0; i < DIV_SIZE; ++i) {
        if (!(divid[i]->isBusy())) continue;
        if (divid[i]->getStatus() != writeback) continue;
        int t = divid[i]->timeDec();
        if (t <= 0) {
            ins_status.reset(divid[i]->getNum(), (int)(divid[i]->getStatus()), cycle);
            double result = 0;
            if (fabs(divid[i]->getVk()) < EPS) {
                cout << "Divided by zero, error occurred.\n";
            }
            assert(fabs(divid[i]->getVk()) >= EPS);
            result = divid[i]->getVj() / divid[i]->getVk();
            updateQ(divid[i], result);
            divid[i]->reset();
        }
    }
}

void check_issue_execute(int cycle) {
    for (int i = 0; i < LOAD_SIZE; ++i) {
        if (!(load[i]->isBusy())) continue;
        if (load[i]->getStatus() != execute) continue;
        int t = load[i]->timeDec();
        if (t <= 0) {
            ins_status.reset(load[i]->getNum(), (int)(load[i]->getStatus()), cycle);
            load[i]->setAddress(load[i]->getVj() + load[i]->getAddress());
            if (load[i]->getOp() == "store") {
                if (load[i]->getQk() == nullptr) {
                    load[i]->setStatus(writeback);
                    load[i]->setTime(1);
                }
            } else { // load
                load[i]->setStatus(writeback);
                load[i]->setTime(1);
            }
        }
    }
    for (int i = 0; i < LOAD_SIZE; ++i) {
        if (load_vis[i]) continue;
        if (!(load[i]->isBusy())) continue;
        if (load[i]->getStatus() != issue) continue;
        load_vis[i] = true;
        int t = load[i]->timeDec();
        if (t <= 0) {
            ins_status.reset(load[i]->getNum(), (int)(load[i]->getStatus()), cycle);
            if (load[i]->getQj() == nullptr) {
                load[i]->setStatus(execute);
                load[i]->setTime(LOAD_TIME);
                break; // the second one should not be removed
            }
        }
    }
    for (int i = 0; i < ADD_SIZE; ++i) {
        if (!(add[i]->isBusy())) continue;
        if (add[i]->getStatus() == writeback) continue;
        int t = add[i]->timeDec();
        if (t <= 0) {
            ins_status.reset(add[i]->getNum(), (int)(add[i]->getStatus()), cycle);
            if (add[i]->getStatus() == issue) {
                if (add[i]->getQj() == nullptr && add[i]->getQk() == nullptr) {
                    add[i]->setStatus(execute);
                    add[i]->setTime(ADD_TIME);
                }
            } else {
                add[i]->setStatus(writeback);
                add[i]->setTime(1);
            }
        }
    }
    for (int i = 0; i < MUL_SIZE; ++i) {
        if (!(mul[i]->isBusy())) continue;
        if (mul[i]->getStatus() == writeback) continue;
        int t = mul[i]->timeDec();
        if (t <= 0) {
            ins_status.reset(mul[i]->getNum(), (int)(mul[i]->getStatus()), cycle);
            if (mul[i]->getStatus() == issue) {
                if (mul[i]->getQj() == nullptr && mul[i]->getQk() == nullptr) {
                    mul[i]->setStatus(execute);
                    mul[i]->setTime(MUL_TIME);
                }
            } else {
                mul[i]->setStatus(writeback);
                mul[i]->setTime(1);
            }
        }
    }
    for (int i = 0; i < DIV_SIZE; ++i) {
        if (!(divid[i]->isBusy())) continue;
        if (divid[i]->getStatus() == writeback) continue;
        int t = divid[i]->timeDec();
        if (t <= 0) {
            ins_status.reset(divid[i]->getNum(), (int)(divid[i]->getStatus()), cycle);
            if (divid[i]->getStatus() == issue) {
                if (divid[i]->getQj() == nullptr && divid[i]->getQk() == nullptr) {
                    divid[i]->setStatus(execute);
                    divid[i]->setTime(DIV_TIME);
                }
            } else {
                divid[i]->setStatus(writeback);
                divid[i]->setTime(1);
            }
        }
    }
}

void tomasulo() {
    check_wb(cycle);
    if (num < ins.size()) {
        Instruction _ins = ins[num];
        bool flag = false;
        if (_ins.Op() == "load" || _ins.Op() == "store") {
            int rs = _ins.Rs(), rt = _ins.Rt();
            for (int i = 0; i < LOAD_SIZE; ++i) {
                if (load[i]->isBusy()) continue;
                // issue
                flag = true;
                tot_time += 2 + LOAD_TIME;
                load[i]->setOp(_ins.Op());
                load[i]->setNum(num);
                load[i]->setStatus(issue);
                load[i]->setTime(1);
                if (Qi[rs] == nullptr) {
                    load[i]->setVj(reg[rs]);
                    load[i]->setQj(nullptr);
                } else {
                    load[i]->setQj(Qi[rs]);
                }
                load[i]->setBusy(true);
                load[i]->setAddress(_ins.Imm());
                if (_ins.Op() == "load") {
                    Qi[rt] = load[i];
                } else {
                    if (Qi[rt] == nullptr) {
                        load[i]->setVk(reg[rt]);
                        load[i]->setQk(nullptr);
                    } else {
                        load[i]->setQk(Qi[rt]);
                    }
                }
                break;
            }
        } else {
            int rs = _ins.Rs(), rt = _ins.Rt(), rd = _ins.Rd();
            if (_ins.Op() == "add.d" || _ins.Op() == "sub.d") {
                for (int i = 0; i < ADD_SIZE; ++i) {
                    if (add[i]->isBusy()) continue;
                    // issue
                    flag = true;
                    tot_time += 2 + ADD_TIME;
                    add[i]->setNum(num);
                    add[i]->setStatus(issue);
                    add[i]->setTime(1);
                    add[i]->setQj(Qi[rs]);
                    if (Qi[rs] == nullptr) add[i]->setVj(reg[rs]);
                    add[i]->setQk(Qi[rt]);
                    if (Qi[rt] == nullptr) add[i]->setVk(reg[rt]);
                    add[i]->setBusy(true);
                    add[i]->setOp(_ins.Op());
                    Qi[rd] = add[i];
                    break;
                }
            } else if (_ins.Op() == "mul.d") {
                for (int i = 0; i < MUL_SIZE; ++i) {
                    if (mul[i]->isBusy()) continue;
                    // issue
                    flag = true;
                    tot_time += 2 + MUL_TIME;
                    mul[i]->setNum(num);
                    mul[i]->setStatus(issue);
                    mul[i]->setTime(1);
                    mul[i]->setQj(Qi[rs]);
                    if (Qi[rs] == nullptr) mul[i]->setVj(reg[rs]);
                    mul[i]->setQk(Qi[rt]);
                    if (Qi[rt] == nullptr) mul[i]->setVk(reg[rt]);
                    mul[i]->setBusy(true);
                    mul[i]->setOp(_ins.Op());
                    Qi[rd] = mul[i];
                    break;
                }
            } else { // div.d
                for (int i = 0; i < DIV_SIZE; ++i) {
                    if (divid[i]->isBusy()) continue;
                    // issue
                    flag = true;
                    tot_time += 2 + DIV_TIME;
                    divid[i]->setNum(num);
                    divid[i]->setStatus(issue);
                    divid[i]->setTime(1);
                    divid[i]->setQj(Qi[rs]);
                    if (Qi[rs] == nullptr) divid[i]->setVj(reg[rs]);
                    divid[i]->setQk(Qi[rt]);
                    if (Qi[rt] == nullptr) divid[i]->setVk(reg[rt]);
                    divid[i]->setBusy(true);
                    divid[i]->setOp(_ins.Op());
                    Qi[rd] = divid[i];
                    break;
                }
            }
        }
        if (flag) ++num;
    }
    check_issue_execute(cycle);
}

//============================================= MEM INITIALIZATION

void mem_initialization() {
    string load_mem = "../mem.txt";
    ifstream IN(load_mem);
    int address; double float_num;
    while (IN >> address >> float_num) {
        assert(address < MEM_SIZE);
        mem[address] = float_num;
    }
    IN.close();
}

//============================================= OUTPUT BUFFER

void output_buffer() {
    ostringstream ostr;
    ostr << "\033[31m\033[1m Instruction Status:\033[0m\n";
    ostr << ins_status;
    ins_status_strings.emplace_back(ostr.str());
    ostr.clear(); ostr.str("");  
    ostr << "\033[31m\033[1m Reservation Stations:\033[0m\n";
    ostr << left << setw(8) << "Name" <<
        setw(8) << "Busy" <<
        setw(8) << "Op" << 
        setw(8) << "Vj" << 
        setw(8) << "Vk" << 
        setw(8) << "Qj" << 
        setw(8) << "Qk" << 
        setw(8) << "Address" << "\n";
    for (int i = 0; i < LOAD_SIZE; ++i) ostr << *load[i] << "\n";
    for (int i = 0; i < ADD_SIZE; ++i) ostr << *add[i] << "\n";
    for (int i = 0; i < MUL_SIZE; ++i) ostr << *mul[i] << "\n";
    for (int i = 0; i < DIV_SIZE; ++i) ostr << *divid[i] << "\n";
    reserve_station_strings.emplace_back(ostr.str());
    ostr.clear(); ostr.str("");
    ostr << "\033[31m\033[1m Register Result Status:\033[0m\n";
    ostr << Qi;
    reg_result_status_strings.emplace_back(ostr.str());
    ostr.clear(); ostr.str("");
}

//============================================= INTERACT

void interact() {
    int nxt = 1;
    bool flag = false;
    char buffer[MAX_N];
    while (true) {
        cout << "Press any keys or words and then press `ENTER' to continue.\n";
        cout << "\033[043m HINT:\033[0m" << " you can type `h' or `help' for help afterwards.\n";
        cout << "> ";
        cin.getline(buffer, MAX_N);
        Signal signal = cmd_parse(buffer, nxt, reg, mem, cycle, 
                    flag, tot_time, (int)ins.size(), 
                    ins_status_strings, 
                    reserve_station_strings, 
                    reg_result_status_strings);
        if (signal == EXIT) return;
        else break;
    }
    ins_status_strings.emplace_back("");
    reserve_station_strings.emplace_back("");
    reg_result_status_strings.emplace_back("");
    while (++cycle) {
        tomasulo();
        output_buffer();
        if (ins_status.isDone()) {
            cout << "\n\033[43m Now is at the end of the cycle:\033[0m" << " " <<
                "\033[36m\033[1m" << cycle << "\033[0m\n";
            cout << ins_status_strings[cycle] << "\n";
            cout << reserve_station_strings[cycle] << "\n";
            cout << reg_result_status_strings[cycle] << "\n";
            cout << "\n\033[43m Execution has been done.\033[0m\n";
            while (true) {
                cout << "> ";
                cin.getline(buffer, MAX_N);
                flag = true;
                Signal signal = cmd_parse(buffer, nxt, reg, mem, cycle, 
                    flag, tot_time, (int)ins.size(), 
                    ins_status_strings, 
                    reserve_station_strings, 
                    reg_result_status_strings);
                if (signal == EXIT) {
                    return;
                } else if (signal == CONTINUE) {
                    continue;
                } else if (signal == STAY) {
                    continue;
                }
            }
            break;
        }
        if (nxt == cycle) {
            cout << "\n\033[43m Now is at the end of the cycle:\033[0m" << " " <<
                "\033[36m\033[1m" << cycle << "\033[0m\n";
            cout << ins_status_strings[cycle] << "\n";
            cout << reserve_station_strings[cycle] << "\n";
            cout << reg_result_status_strings[cycle] << "\n";
            nxt = cycle + 1;
            while (true) {
                cout << "> ";
                cin.getline(buffer, MAX_N);
                Signal signal = cmd_parse(buffer, nxt, reg, mem, cycle, 
                    flag, tot_time, (int)ins.size(), 
                    ins_status_strings, 
                    reserve_station_strings, 
                    reg_result_status_strings);
                if (signal == EXIT) {
                    return;
                } else if (signal == CONTINUE) {
                    break;
                } else if (signal == STAY) {
                    continue;
                }
            }
        }
    }
}

//============================================= MAIN

int main(int argc, char *argv[]) {
    mem_initialization();
    char buffer[MAX_N];
    string input = "../sample.s";
    if (argc > 1) input = argv[1];
    ifstream IN(input);
    cout << "Now you are loading the file: " << input << "\n";
    cout << "=======================================================\n";
    vector<string> __ins;
    while (IN.getline(buffer, MAX_N)) {
        cout << buffer << "\n";
        Instruction _ins;
        string now_ins = char_to_string(buffer);
        __ins.emplace_back(now_ins);
        _ins.reset(now_ins);
        ins.emplace_back(_ins);
    }
    cout << "==========================END==========================\n";
    IN.close();
    for (int i = 0; i < LOAD_SIZE; ++i) {
        load[i] = new ReserveStation;
        ostringstream ostr;
        ostr << "LOAD" << i + 1;
        load[i]->setName(ostr.str());
    }
    for (int i = 0; i < ADD_SIZE; ++i) {
        add[i] = new ReserveStation;
        ostringstream ostr;
        ostr << "ADD" << i + 1;
        add[i]->setName(ostr.str());
    }
    for (int i = 0; i < MUL_SIZE; ++i) {
        mul[i] = new ReserveStation;
        ostringstream ostr;
        ostr << "MUL" << i + 1;
        mul[i]->setName(ostr.str());
    }
    for (int i = 0; i < DIV_SIZE; ++i) {
        divid[i] = new ReserveStation;
        ostringstream ostr;
        ostr << "DIV" << i + 1;
        divid[i]->setName(ostr.str());
    }
    ins_status.reset(__ins);

//============================================= INITIALIZATION DONE

    interact();

//============================================= FREE MEMORY

    for (int i = 0; i < LOAD_SIZE; ++i) delete load[i];
    for (int i = 0; i < ADD_SIZE; ++i) delete add[i];
    for (int i = 0; i < MUL_SIZE; ++i) delete mul[i];
    for (int i = 0; i < DIV_SIZE; ++i) delete divid[i];
    return 0;
}