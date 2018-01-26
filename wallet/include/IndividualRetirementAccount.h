#ifndef INDIVIDUALRETIREMENTACCOUNT_H
#define INDIVIDUALRETIREMENTACCOUNT_H
#include<string>
#include<iostream>
#include "Asset.h"
#include<stdlib.h>
#include <sstream>
#include<fstream>
#include "Utils.h"

class IndividualRetirementAccount : public Asset
{
    public:
        IndividualRetirementAccount();
        IndividualRetirementAccount(std::string b, double i, double amount);
        std::string getInstitution();
        double getInterest();
        void setInstitution(std::string b);
        void setInterest(double i);
        double simulate();
        void showInfo();
        void edit();
        std::string serialize();
        void deserialize(std::ifstream & myfile);
    private:
        std::string institution;
        double interest;
};

#endif // INDIVIDUALRETIREMENTACCOUNT_H
