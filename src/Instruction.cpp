#include "Instruction.h"
#include "String.h"

Instruction::Instruction() {
    op = "";
    rt = rs = rd = imm = 0;
}

Instruction::Instruction(std::string _instruction, std::string _op, int _rs, int _rt, int _rd, int _imm) : 
    instruction(_instruction), op(_op), rs(_rs), rt(_rt), rd(_rd), imm(_imm) {}

Instruction::~Instruction() {}

void Instruction::reset(std::string s) {
    s = to_lower_case(s);
    instruction = s;
    std::vector<std::string> ins;
    ins = split(s);
    if (!ins.size()) return;
    if (ins[0] == "load" || ins[0] == "store") {
        if (ins.size() != 4) return;
        op = ins[0];
        rt = string_to_integer(ins[1]);
        imm = string_to_integer(ins[2]);
        rs = string_to_integer(ins[3]) + 16;
        rd = 0;
    } else if (ins[0] == "add.d" || ins[0] == "sub.d" || 
        ins[0] == "mul.d" || ins[0] == "div.d") {
        if (ins.size() != 4) return;
        op = ins[0];
        rd = string_to_integer(ins[1]);
        rs = string_to_integer(ins[2]);
        rt = string_to_integer(ins[3]);
        imm = 0;
    }
}

std::string Instruction::Op() const { return op; }
int Instruction::Rs() const { return rs; }
int Instruction::Rt() const { return rt; }
int Instruction::Rd() const { return rd; }
int Instruction::Imm() const { return imm; }

std::ostream &operator<<(std::ostream &out, const Instruction &ins) {
    out << ins.op << ": " << ins.rd << " " << ins.rs << " " << ins.rt << " " << ins.imm;
    return out;
}