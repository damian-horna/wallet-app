#ifndef UTILS_H
#define UTILS_H
#include<string>
#include <regex>
#include<iostream>

class Utils
{
public:
    Utils();
    bool is_number(const std::string& s);
    bool is_date(const std::string & s);
    bool is_double(const std::string &s);
private:
};

#endif // UTILS_H
