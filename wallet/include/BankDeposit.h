#ifndef BANKDEPOSIT_H
#define BANKDEPOSIT_H
#include "Asset.h"
#include<string>
#include<iostream>
#include<stdlib.h>
#include <sstream>
#include<fstream>
#include "Utils.h"

class BankDeposit : public Asset
{
    public:
        BankDeposit();
        BankDeposit(std::string b, double i, double amount);
        std::string getBank();
        void setBank(std::string b);
        double getInterest();
        void setInterest(double i);
        double simulate();
        void showInfo();
        void edit();
        std::string serialize();
        void deserialize(std::ifstream& myfile);
    private:
        double interest;
        std::string bank;
};

#endif // BANKDEPOSIT_H
