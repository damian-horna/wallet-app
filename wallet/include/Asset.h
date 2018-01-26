#ifndef ASSET_H
#define ASSET_H
#include <string>
#include<sstream>
#include<fstream>

class Asset
{
    public:
        std::string getName();
        void setName(std::string name);
        double getValue();
        void setValue(double value);
        virtual double simulate()=0;
        virtual void showInfo()=0;
        virtual void edit()=0;
        virtual std::string serialize()=0;
        virtual void deserialize(std::ifstream& myfile)=0;
    private:
        std::string name;
        double value;
};

#endif // ASSET_H
