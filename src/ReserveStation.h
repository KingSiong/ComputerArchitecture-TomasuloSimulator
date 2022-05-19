#ifndef RESERVESTATION_H_
#define RESERVESTATION_H_
#include <string>
#include <iostream>
#include <iomanip>

enum PipeLine {issue, execute, writeback};
class ReserveStation {
private:
    std::string op;
    ReserveStation *qj, *qk;
    double vj, vk;
    bool busy;
    int address;
    int ins_num;
    int _time;
    PipeLine status;
    std::string name;
public:
    ReserveStation();
    ~ReserveStation();
    
    std::string getOp() const;
    ReserveStation *getQj() const;
    ReserveStation *getQk() const;
    double getVj() const;
    double getVk() const;
    bool isBusy() const;
    int getAddress() const;
    int getNum() const;
    int getTime() const;
    PipeLine getStatus() const;
    std::string getName() const;

    std::string setOp(std::string s);
    ReserveStation *setQj(ReserveStation *r);
    ReserveStation *setQk(ReserveStation *r);
    double setVj(double v);
    double setVk(double v);
    bool setBusy(bool flag);
    int setNum(int num);
    int setAddress(int a);
    PipeLine setStatus(PipeLine st);
    int setTime(int t);
    std::string setName(std::string _name);
    
    void reset();
    
    int timeDec();

    friend std::ostream &operator<<(std::ostream &out, const ReserveStation &r);
};

#endif