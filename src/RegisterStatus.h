#ifndef REGISTERSTATUS757_H_
#define REGISTERSTATUS757_H_
#include <vector>
#include <iostream>
#include <iomanip>
#include "ReserveStation.h"

class RegisterStatus {
private:
    std::vector< ReserveStation* > q;
    unsigned int n;
public:
    RegisterStatus();
    RegisterStatus(int _n);
    ~RegisterStatus();

    void reset(unsigned int _n);
    unsigned int size() const;
    ReserveStation *&operator[](const int &k);

    friend std::ostream &operator<<(std::ostream &out, const RegisterStatus &rs);
};

#endif