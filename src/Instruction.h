#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_
#include <iostream>
#include <string>

class Instruction {
private:
    std::string instruction;
    std::string op;
    int rs, rt, rd;
    int imm;
public:
    Instruction();
    Instruction(std::string _instruction, std::string _op, int _rt, int _rs, int _rd, int _imm);
    ~Instruction();

    void reset(std::string ins);
    std::string Op() const;
    int Rs() const;
    int Rt() const;
    int Rd() const;
    int Imm() const;
    friend std::ostream &operator<<(std::ostream &out, const Instruction &ins);
};

#endif