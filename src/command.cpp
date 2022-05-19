#include "command.h"

void show_freg(int num, double *reg) {
    if (~num) {
        if (num >= REG_SIZE) {
            std::cout << "segmentation fault. the size of float register file if not so big.\n";
        } else {
            std::cout << "float register" << "[" << num << "]: " << reg[num] << "\n";
        }
    } else {
        for (int i = 0; i < REG_SIZE; ++i) 
            std::cout << "float register" << "[" << i << "]: " << reg[i] << "\n";
    }
}

void show_reg(int num, double *reg) {
    if (~num) {
        if (num >= REG_SIZE) {
            std::cout << "segmentation fault. the size of register file if not so big.\n";
        } else {
            std::cout << "register" << "[" << num << "]: " << (int)(reg[num + REG_SIZE]) << "\n";
        }
    } else {
        for (int i = 0; i < REG_SIZE; ++i) 
            std::cout << "register" << "[" << i << "]: " << (int)reg[i + REG_SIZE] << "\n";
    }
}

void show_mem(int num, double *mem) {
    if (~num) {
        if (num >= MEM_SIZE) {
            std::cout << "segmentation fault. the size of memory if not so big.\n";
        } else {
            std::cout << "memory" << "[" << num << "]: " << mem[num] << "\n";
        }
    } else {
        for (int i = 0; i < MEM_SIZE; ++i) 
            std::cout << "memory" << "[" << i << "]: " << mem[i] << "\n";
    }
}

void show_is(const int &cycle, int _cycle, const std::vector<std::string> &ins_status_strings) {
    if (_cycle > cycle) {
        std::cout << "command is: cycle you input is too large.\n";
    } else {
        std::cout << ins_status_strings[_cycle] << "\n";
    }
}

void show_rs(const int &cycle, int _cycle, const std::vector<std::string> &reserve_station_strings) {
    if (_cycle > cycle) {
        std::cout << "command rs: cycle you input is too large.\n";
    } else {
        std::cout << reserve_station_strings[_cycle] << "\n";
    }
}

void show_rrs(const int &cycle, int _cycle, const std::vector<std::string> &reg_result_status_strings) {
    if (_cycle > cycle) {
        std::cout << "command rrs: cycle you input is too large.\n";
    } else {
        std::cout << reg_result_status_strings[_cycle] << "\n";
    }
}

void show_through_put(const int &cycle, bool flag, const int &tot_num) {
    if (!flag) {
        std::cout << "instructions are still running.\n";
        return;
    }
    std::cout << "through put is: " << std::setiosflags(std::ios::fixed) << std::setprecision(6) << 
        1.0 * tot_num / cycle << " (IPC)\n";
}

void show_efficiency(const int &cycle, bool flag, const int &tot_time) {
    if (!flag) {
        std::cout << "instructions are still running.\n";
        return;
    }
    std::cout << "efficiency is: " << std::setiosflags(std::ios::fixed) << std::setprecision(6) << 
        1.0 * tot_time / (cycle * 3) << "\n";
}

void show_speedup(const int &cycle, bool flag, const int &tot_time) {
    if (!flag) {
        std::cout << "instructions are still running.\n";
        return;
    }
    std::cout << "speedup is: " << std::setiosflags(std::ios::fixed) << std::setprecision(6) << 
        1.0 * tot_time / cycle << "\n";
}

void show_help() {
    std::cout << "======================================= help =======================================\n";
    std::cout << "\033[43m INTERNAL COMMAND:\033[0m\n"; // internal
    // exit
    std::cout << "\033[32m\033[1mexit, \033[0m";
    std::cout << "\033[32m\033[1mq, \033[0m";
    std::cout << "\033[32m\033[1mQ\033[0m :";
    std::cout << "to exit from this process.\n";
    // continue
    std::cout << "\033[32m\033[1mCONTINUE, \033[0m";
    std::cout << "\033[32m\033[1mcontinue, \033[0m";
    std::cout << "\033[32m\033[1mC, \033[0m";
    std::cout << "\033[32m\033[1mc\033[0m :";
    std::cout << "to continue next step while running step by step.\n";
    // run to the end
    std::cout << "\033[32m\033[1mrte\033[0m :";
    std::cout << "to run the procedure to the end.\n";    
    // jmp
    std::cout << "\033[32m\033[1mjmp [num]\033[0m :";
    std::cout << "to jmp num steps or 1 step by default.\n";
    // memory
    std::cout << "\033[32m\033[1mmem [num]\033[0m :";
    std::cout << "to show the certain memory[num] or all memories' status by default.\n";
    // float register
    std::cout << "\033[32m\033[1mfreg [num]\033[0m :";
    std::cout << "to show the certain float register[num] or all registers' status by default.\n";
    // register
    std::cout << "\033[32m\033[1mreg [num]\033[0m :";
    std::cout << "to show the certain register[num] or all registers' status by default.\n";
    // instruction status
    std::cout << "\033[32m\033[1mis [cycle]\033[0m :";
    std::cout << "to show instruction status on particular cycle or now by default.\n";
    // reservation stations
    std::cout << "\033[32m\033[1mrs [cycle]\033[0m :";
    std::cout << "to show reservation stations on particular cycle or now by default.\n";
    // register result status
    std::cout << "\033[32m\033[1mrrs [cycle]\033[0m :";
    std::cout << "to show register result status on particular cycle or now by default.\n";
    // through put
    std::cout << "\033[32m\033[1mtp, TP\033[0m :";
    std::cout << "to show the through put after all instructions were done.\n";
    // speedup
    std::cout << "\033[32m\033[1ms, S\033[0m :";
    std::cout << "to show the speedup after all instrutions were done.\n";
    // efficiency
    std::cout << "\033[32m\033[1me, E\033[0m :";
    std::cout << "to show the efficiency after all instructions were done.\n";
    // help
    std::cout << "\033[32m\033[1mh, help\033[0m :";
    std::cout << "to show the help documentation as you can see now.\n";
    std::cout << "====================================================================================\n";
}

Signal cmd_parse(std::string cmd, int &nxt, double *reg, double *mem, const int &cycle, 
    bool flag, const int &tot_time, const int &tot_num, 
    const std::vector<std::string> &ins_status_strings, 
    const std::vector<std::string> &reserve_station_strings, 
    const std::vector<std::string> &reg_result_status_strings) {
    std::vector<std::string> cmd_vector = split(cmd);
    if (!cmd_vector.size()) return STAY;
    if (cmd_vector[0] == "q" || cmd_vector[0] == "Q" || cmd_vector[0] == "exit" || cmd_vector[0] == "EXIT") {
        return EXIT;
    } else if (cmd_vector[0] == "c" || cmd_vector[0] == "C" 
        || cmd_vector[0] == "continue" || cmd_vector[0] == "CONTINUE") {
        return CONTINUE;
    } else if (cmd_vector[0] == "reg") {
        int num = -1;
        if (cmd_vector.size() > 1) {
            if (chk_int(cmd_vector[1])) {
                num = string_to_integer(cmd_vector[1]);
                if (num < 0) {
                    std::cout << "command reg: register index should not less than 0.\n";
                } else {
                    show_reg(num, reg);
                }
            } else {
                std::cout << "command reg: register index should be an unsigned integer.\n";
            }
        } else {
            show_reg(num, reg);
        }
        return STAY;
    } else if (cmd_vector[0] == "freg") {
        int num = -1;
        if (cmd_vector.size() > 1) {
            if (chk_int(cmd_vector[1])) {
                num = string_to_integer(cmd_vector[1]);
                if (num < 0) {
                    std::cout << "command freg: register index should not less than 0.\n";
                } else {
                    show_freg(num, reg);
                }
            } else {
                std::cout << "command freg: register index should be an unsigned integer.\n";
            }
        } else {
            show_freg(num, reg);
        }
        return STAY; 
    } else if (cmd_vector[0] == "mem") {
        int num = -1;
        if (cmd_vector.size() > 1) {
            if (chk_int(cmd_vector[1])) {
                num = string_to_integer(cmd_vector[1]);
                if (num < 0) {
                    std::cout << "command mem: memory index should not less than 0.\n";
                } else {
                    show_mem(num, mem);
                }
            } else {
                std::cout << "command mem: memory index should be an unsigned integer.\n";
            }
        } else {
            show_mem(num, mem);
        }
        return STAY;
    } else if (cmd_vector[0] == "h" || cmd_vector[0] == "help") {
        show_help();
        return STAY;
    } else if (cmd_vector[0] == "rte") { // run to the end
        nxt = -1;
        return CONTINUE;
    } else if (cmd_vector[0] == "is") { // instruction status
        int _cycle = cycle;
        if (cmd_vector.size() > 1) {
            if (chk_int(cmd_vector[1])) {
                _cycle = string_to_integer(cmd_vector[1]);
                if (_cycle < 0) {
                    std::cout << "command is: cycle can't be negtive.\n";
                } else {
                    show_is(cycle, _cycle, ins_status_strings);
                }
            } else {
                std::cout << "command is: cycle should be an usigned integer.\n";
            }
        } else {
            show_is(cycle, _cycle, ins_status_strings);
        }
        return STAY;
    } else if (cmd_vector[0] == "rs") { // reservation station
        int _cycle = cycle;
        if (cmd_vector.size() > 1) {
            if (chk_int(cmd_vector[1])) {
                _cycle = string_to_integer(cmd_vector[1]);
                if (_cycle < 0) {
                    std::cout << "command rs: cycle can't be negtive.\n";
                } else {
                    show_rs(cycle, _cycle, reserve_station_strings);
                }
            } else {
                std::cout << "command rs: cycle should be an usigned integer.\n";
            }
        } else {
            show_rs(cycle, _cycle, reserve_station_strings);
        }
        return STAY;
    } else if (cmd_vector[0] == "rrs") {
        int _cycle = cycle;
        if (cmd_vector.size() > 1) {
            if (chk_int(cmd_vector[1])) {
                _cycle = string_to_integer(cmd_vector[1]);
                if (_cycle < 0) {
                    std::cout << "command rs: cycle can't be negtive.\n";
                } else {
                    show_rrs(cycle, _cycle, reg_result_status_strings);
                }
            } else {
                std::cout << "command is: cycle should be an usigned integer.\n";
            }
        } else {
            show_rrs(cycle, _cycle, reg_result_status_strings);
        }
        return STAY;        
    } else if (cmd_vector[0] == "tp" || cmd_vector[0] == "TP") {
        show_through_put(cycle, flag, tot_num);
        return STAY;
    } else if (cmd_vector[0] == "s" || cmd_vector[0] == "S") {
        show_speedup(cycle, flag, tot_time);
        return STAY;
    } else if (cmd_vector[0] == "e" || cmd_vector[0] == "E") {
        show_efficiency(cycle, flag, tot_time);
        return STAY;
    } else if (cmd_vector[0] == "jmp") {
        int step = 1;
        if (cmd_vector.size() > 1) {
            if (chk_int(cmd_vector[1])) {
                step = string_to_integer(cmd_vector[1]);
                if (step < 0) {
                    std::cout << "command jmp: jumping step can't be negtive.\n";
                    step = 1;
                }
            }
        }
        nxt = cycle + step;
        return CONTINUE;
    }
    if (tot_time) std::cout << "invalid command. please check what you typed and try again.\n";
    return STAY;
}