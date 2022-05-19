#include "ReserveStation.h"

ReserveStation::ReserveStation() {
    op = "";
    qj = nullptr;
    qk = nullptr;
    vj = vk = 0;
    busy = false;
    address = 0;
    ins_num = 0;
    _time = 0;
    status = issue;
}

ReserveStation::~ReserveStation() {}

std::string ReserveStation::getOp() const { return op; }
ReserveStation *ReserveStation::getQj() const { return qj; }
ReserveStation *ReserveStation::getQk() const { return qk; }
double ReserveStation::getVj() const { return vj; }
double ReserveStation::getVk() const { return vk; }
bool ReserveStation::isBusy() const { return busy; }
int ReserveStation::getAddress() const { return address; }
int ReserveStation::getNum() const { return ins_num; }
PipeLine ReserveStation::getStatus() const { return status; }
int ReserveStation::getTime() const { return _time; }
std::string ReserveStation::getName() const { return name; }

std::string ReserveStation::setOp(std::string s) { return op = s; }
ReserveStation *ReserveStation::setQj(ReserveStation *r) { return qj = r; }
ReserveStation *ReserveStation::setQk(ReserveStation *r) { return qk = r; }
double ReserveStation::setVj(double v) { return vj = v; }
double ReserveStation::setVk(double v) { return vk = v; }
bool ReserveStation::setBusy(bool flag) { return busy = flag; }
int ReserveStation::setAddress(int a) { return address = a; }
int ReserveStation::setNum(int num) { return ins_num = num; }
PipeLine ReserveStation::setStatus(PipeLine st) { return status = st; }
int ReserveStation::setTime(int t) { return _time = t; }
std::string ReserveStation::setName(std::string _name) { return name = _name; }

void ReserveStation::reset() {
    op = "";
    qj = nullptr;
    qk = nullptr;
    vj = vk = 0;
    busy = false;
    address = 0;
    ins_num = 0;
    _time = 0;
    status = issue;
}

int ReserveStation::timeDec() { return --_time; }

std::ostream &operator<<(std::ostream &out, const ReserveStation &r) {
    out << std::left << std::setw(8) << r.name <<
        std::setw(8) << (r.busy ? "Yes" : "No") <<
        std::setw(8) << r.op << 
        std::setw(8) << r.vj <<
        std::setw(8) << r.vk;
    if (r.qj == nullptr) out << std::setw(8) << "0";
    else out << std::setw(8) << r.qj->getName();
    if (r.qk == nullptr) out << std::setw(8) << "0";
    else out << std::setw(8) << r.qk->getName();
    out << std::setw(8) << r.address;
    return out;
}
