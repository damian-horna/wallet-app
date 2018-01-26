#ifndef REALESTATE_H
#define REALESTATE_H
#include "Asset.h"
#include<string>
#include<iostream>
#include<stdlib.h>
#include <sstream>
#include<fstream>
#include "Utils.h"

class RealEstate : public Asset
{
    public:
        RealEstate();
        RealEstate(std::string address, double rent);
        double getRent();
        void setRent(double rent);
        std::string getAddress();
        void setAddress(std::string adr);
        double simulate();
        void showInfo();
        void edit();
        std::string serialize();
        void deserialize(std::ifstream & toDeserialize);
    private:
        double rent;
        std::string address;
};

#endif // REALESTATE_H
