#ifndef COMMAND_H_
#define COMMAND_H_
#include "String.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

extern const int REG_SIZE;
extern const int MEM_SIZE;

void show_freg(int num, double *reg);
void show_reg(int num, double *reg);
void show_mem(int num, double *mem);
void show_is(const int &cycle, int _cycle, const std::vector<std::string> &ins_status_strings);
void show_rs(const int &cycle, int _cycle, const std::vector<std::string> &reserve_station_strings);
void show_rrs(const int &cycle, int _cycle, const std::vector<std::string> &reg_result_status_strings);
void show_help();

enum Signal {EXIT, CONTINUE, STAY};

Signal cmd_parse(std::string cmd, int &nxt, double *reg, double *mem, const int &cycle, 
    bool flag, const int &tot_time, const int &tot_num, 
    const std::vector<std::string> &ins_status_strings, 
    const std::vector<std::string> &reserve_station_strings, 
    const std::vector<std::string> &reg_result_status_strings);

#endif