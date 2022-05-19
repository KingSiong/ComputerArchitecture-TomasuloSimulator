#include "String.h"

std::string to_lower_case(std::string s) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 'a' - 'A';
        }
    }
    return s;
}

std::vector<std::string> split(std::string s) {
    std::vector<std::string> res;
    s = s + " ";
    int n = s.size();
    std::string item = "";
    for (int i = 0; i < n; ++i) {
        if (s[i] != ' ' && s[i] != ',' && s[i] != '(' && s[i] != ')') {
            item = item + s[i];
        } else {
            if (item.size()) res.emplace_back(item);
            item = "";
        }
    }
    return res;
}

int string_to_integer(std::string s) {
    int res = 0, n = s.size(), f = 1;
    int i = 0;
    if (n && s[i] == '-') f = -1, ++i;
    for (; i < n; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            res = res * 10 + s[i] - '0';
        }
    }
    return res * f;
}

std::string char_to_string(char *s) {
    std::string res = "";
    for (int i = 0; s[i] != 0; ++i) {
        res = res + s[i];
    }
    return res;
}

bool chk_int(std::string s) {
    int n = s.size();
    int i = 0;
    if (n && s[i] == '-') ++i;
    for (; i < n; ++i) if (s[i] > '9' || s[i] < '0') return false;
    return true;
}