#ifndef INVESTMENTFUNDSHARE_H
#define INVESTMENTFUNDSHARE_H
#include<string>
#include<iostream>
#include "Asset.h"
#include<stdlib.h>
#include <sstream>
#include<fstream>
#include "Utils.h"

class InvestmentFundShare : public Asset
{
    public:
        InvestmentFundShare();
        InvestmentFundShare(std::string name, double amount);
        std::string getFundName();
        void setFundName(std::string name);
        double simulate();
        void showInfo();
        void edit();
        std::string serialize();
        void deserialize(std::ifstream & myfile);
    private:
        std::string fundName;
};

#endif // INVESTMENTFUNDSHARE_H
