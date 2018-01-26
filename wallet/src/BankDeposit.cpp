#include "BankDeposit.h"
using namespace std;
BankDeposit::BankDeposit()
{
    //ctor
}

BankDeposit::BankDeposit(std::string b, double i, double amount){
    this->setName("Deposit in "+b);
    this->setValue(amount);
    bank = b;
    interest = i;
}
std::string BankDeposit::getBank(){
    return bank;
}
void BankDeposit::setBank(std::string b){
    bank = b;
}
double BankDeposit::getInterest(){
    return interest;
}
void BankDeposit::setInterest(double i){
    interest = i;
}
double BankDeposit::simulate(){
    this->setValue(this->getValue() + ((interest/365)*this->getValue()));
    return this->getValue();
}
void BankDeposit::showInfo(){
    std::cout<<"Name of asset: "<<this->getName()<<endl;
    std::cout<<"Name of bank: "<<this->getBank()<<endl;
    std::cout<<"Interest: "<<this->getInterest()<<endl;
    std::cout<<"Value: $"<<this->getValue()<<endl;
}
void BankDeposit::edit(){
    bool exit = false;
    int propertyNumber;
    std::string newName, newBankName;
    double newInterest=0, newValue=0;

    while(!exit){
        std::cout<<"1. Name of asset: "<<this->getName()<<endl;
        std::cout<<"2. Name of bank: "<<this->getBank()<<endl;
        std::cout<<"3. Interest: "<<this->getInterest()<<endl;
        std::cout<<"4. Value: $"<<this->getValue()<<endl;
        std::cout<<"5. I am done editing. Go back."<<endl;
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
            std::cout<<"New bank name: ";
            std::cin.ignore();
            getline(std::cin, newBankName);
            bank = newBankName;
            system("cls");
            break;
        case 3:
            while(!isValid){
                std::cout<<msg;
                std::cout<<"New interest: ";
                std::cin>>inp;
                if(utils.is_double(inp)){
                    isValid=true;
                    newInterest = atof( inp.c_str() );
                    msg="";
                }else{
                    msg = "This is not a proper interest!\n";
                }
            }
            isValid=false;
            msg="";
            interest = newInterest;
            system("cls");
            break;
        case 4:
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
        case 5:
            exit = true;
            break;
    }

    }

}

std::string BankDeposit::serialize(){
    std::stringstream s;
    s << "-deposit-" <<'\n'<< this->getName() << '\n' << this->getValue() << '\n' << this->getBank() << '\n' << this->getInterest()<<'\n';
    return s.str();
}

void BankDeposit::deserialize(std::ifstream& myfile){
    char c;
    std::string line;
    double value,interest;
    getline (myfile,line);
    this->setName(line);
    myfile >> value;
    while (myfile.get(c) && c != '\n'){

    }
    getline(myfile, line);
    this->setBank(line);
    myfile >> interest;
    while (myfile.get(c) && c != '\n'){
    }
    this->setValue(value);
    this->setInterest(interest);

}
