#include "RegisterStatus.h"
#include <iostream>

RegisterStatus::RegisterStatus() : n(0) {
    q.resize(n);
}

RegisterStatus::RegisterStatus(int _n) : n(_n) {
    q.resize(n);
}

void RegisterStatus::reset(unsigned int _n) {
    n = _n;
    q.resize(n);
}

RegisterStatus::~RegisterStatus() {}

unsigned int RegisterStatus::size() const {
    return this->n;
}

ReserveStation *&RegisterStatus::operator [] (const int &k) {
    return q[k];
}

std::ostream &operator<<(std::ostream &out, const RegisterStatus &rs) {
    out << std::left;
    for (int i = 0; i < rs.n / 2; ++i) out << std::setw(6) << i;
    out << std::endl;
    out << std::left;
    for (int i = 0; i < rs.n / 2; ++i) {
        if (rs.q[i] == nullptr) {
            out << std::setw(6) << "0";
        } else {
            out << std::setw(6) << rs.q[i]->getName();
        }
    }
    out << std::endl;
    return out;
}