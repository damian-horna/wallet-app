#ifndef CONTRACT_H
#define CONTRACT_H
#include "Date.h"
#include "Asset.h"
#include<iostream>
#include<stdlib.h>
#include <sstream>
#include<fstream>
#include "Utils.h"

class Contract : public Asset
{
    public:
        Contract();
        Contract(std::string name, double m, double amount);
        double getMultiplier();
        void setMultiplier(double);
        double simulate();
        void showInfo();
        void edit();
        std::string serialize();
        void deserialize(std::ifstream & myfile);
    private:
        double multiplier;

};

#endif // CONTRACT_H
