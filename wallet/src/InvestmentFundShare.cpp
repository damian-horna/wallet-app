#include "InvestmentFundShare.h"

InvestmentFundShare::InvestmentFundShare(){
}

InvestmentFundShare::InvestmentFundShare(std::string n, double amount){
    this->setValue(amount);
    this->setName("Investment fund shares in "+n);
    fundName = n;
}

std::string InvestmentFundShare::getFundName(){
return fundName;
}
void InvestmentFundShare::setFundName(std::string n){
fundName = n;
}
double InvestmentFundShare::simulate(){
    if(((((rand() % 10) + 1 ) % 2) == 0) && (this->getValue()/20) != 0){

        this->setValue(this->getValue() - this->getValue()/20);

    }else this->setValue(this->getValue() + this->getValue()/20);
    return this->getValue();
}
void InvestmentFundShare::showInfo(){
    std::cout<<"Name of asset: "<<this->getName()<<std::endl;
    std::cout<<"Name of fund: "<<this->getFundName()<<std::endl;
    std::cout<<"Value: $"<<this->getValue()<<std::endl;
}
void InvestmentFundShare::edit(){
    bool exit = false;
    int propertyNumber;
    std::string newName, newBankName;
    double newValue=0;

    while(!exit){
        std::cout<<"1. Name of asset: "<<this->getName()<<std::endl;
        std::cout<<"2. Name of fund: "<<this->getFundName()<<std::endl;
        std::cout<<"3. Value: $"<<this->getValue()<<std::endl;
        std::cout<<"4. I am done editing. Go back."<<std::endl;
        Utils utils;
        bool isValid = false;
        std::string inp, msg="";
        while(!isValid){
                std::cout<<msg;
                std::cout<<"What property you want to edit?"<<std::endl;
                std::cin>>inp;
                if(utils.is_number(inp)){
                    isValid=true;
                    propertyNumber = atof( inp.c_str() );
                    msg="";
                }else{
                    msg = "This is not a valid number!\n";
                }
        }
        isValid = false;
        msg = "";
        switch(propertyNumber){
        case 1:
            std::cout<<"New asset name: ";
            std::cin.ignore();
            getline(std::cin, newName);
            this->setName(newName);
            system("cls");
            break;
        case 2:
            std::cout<<"New fund name: ";
            std::cin.ignore();
            getline(std::cin, newBankName);
            fundName = newBankName;
            system("cls");
            break;
        case 3:
            while(!isValid){
                std::cout<<msg;
                std::cout<<"New value: ";
                std::cin>>inp;
                if(utils.is_double(inp)){
                    isValid=true;
                    newValue = atof( inp.c_str() );
                    msg="";
                }else{
                    msg = "This is not a proper value!\n";
                }
            }
            isValid=false;
            msg="";
            this->setValue(newValue);
            system("cls");
            break;
        case 4:
            exit = true;
            break;
    }

    }

}

std::string InvestmentFundShare::serialize(){
    std::stringstream s;
    s << "-fundshares-" <<'\n'<< this->getName() << '\n' << this->getValue() << '\n' << this->getFundName()<<'\n';
    return s.str();
}

void InvestmentFundShare::deserialize(std::ifstream & myfile){
    char c;
    std::string line;
    double value;
    getline (myfile,line);
    this->setName(line);
    myfile >> value;
    while (myfile.get(c) && c != '\n'){

    }
    getline(myfile, line);
    this->setFundName(line);
    this->setValue(value);
}
