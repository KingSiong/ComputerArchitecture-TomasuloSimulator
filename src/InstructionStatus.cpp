#include "InstructionStatus.h"

InstructionStatus::InstructionStatus() : n(0) {
    ins.resize(n);
    ins_status.resize(n, std::vector<int>(3, 0));
}
    
InstructionStatus::InstructionStatus(int _n) : n(_n) {
    ins.resize(n);
    ins_status.resize(n, std::vector<int>(3, 0));
}

InstructionStatus::~InstructionStatus() {}

void InstructionStatus::reset(std::vector< std::string > _ins) {
    n = _ins.size();
    ins.resize(n);
    ins_status.resize(n, std::vector<int>(3, 0));
    for (int i = 0; i < n; ++i) ins[i] = _ins[i];
}

void InstructionStatus::reset(int i, int j, int cycle) {
    if (!ins_status[i][j]) ins_status[i][j] = cycle;
}

bool InstructionStatus::isDone() const {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!ins_status[i][j]) return false;
        }
    }
    return true;
}
    
std::ostream &operator<<(std::ostream &out, const InstructionStatus &InsStatus) {
    out << std::left << std::setw(24) << "Instruction" << 
        std::setw(12) << "Issue" << std::setw(12) << "Exec Comp" << std::setw(12) << "Write Result" << std::endl;
    for (int i = 0; i < InsStatus.n; ++i) {
        out << std::left << std::setw(24) << InsStatus.ins[i];
        for (int j = 0; j < 3; ++j) {
            out << std::setw(12) << InsStatus.ins_status[i][j];
        }
        out << std::endl;
    }
    return out;
}