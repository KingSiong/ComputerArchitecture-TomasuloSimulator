#ifndef INSTRUCTIONSTATUS_H_
#define INSTRUCTIONSTATUS_H_
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

class InstructionStatus {
private:
    std::vector< std::string > ins;
    std::vector< std::vector<int> > ins_status;
    unsigned int n;
public:
    InstructionStatus();
    InstructionStatus(int _n);
    ~InstructionStatus();

    void reset(std::vector< std::string > _ins);
    void reset(int i, int j, int cycle);
    bool isDone() const;
    friend std::ostream &operator<<(std::ostream &out, const InstructionStatus &InsStatus);
};

#endif