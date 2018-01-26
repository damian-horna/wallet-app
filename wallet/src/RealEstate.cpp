#include "RealEstate.h"

RealEstate::RealEstate()
{
    //ctor
}

RealEstate::RealEstate(std::string addr, double r){
    this->setName("Real estate located at "+ addr);
    this->setValue(0);
    address = addr;
    rent = r;
}
double RealEstate::getRent(){
    return rent;
}
void RealEstate::setRent(double r){
    rent = r;
}
std::string RealEstate::getAddress(){
return address;
}
void RealEstate::setAddress(std::string adr){
address = adr;
}
double RealEstate::simulate(){
    this->setValue(this->getValue() + this->getRent()/30);
    return this->getValue();
}
void RealEstate::showInfo(){
    std::cout<<"Name of asset: "<<this->getName()<<std::endl;
    std::cout<<"Address: "<<this->getAddress()<<std::endl;
    std::cout<<"Rent: "<<this->getRent()<<std::endl;
    std::cout<<"Value: $"<<this->getValue()<<std::endl;
}
void RealEstate::edit(){
    bool exit = false;
    int propertyNumber;
    std::string newName, newBankName;
    double newRent=0, newValue=0;

    while(!exit){
        std::cout<<"1. Name of asset: "<<this->getName()<<std::endl;
        std::cout<<"2. Address: "<<this->getAddress()<<std::endl;
        std::cout<<"3. Rent: $"<<this->getRent()<<std::endl;
        std::cout<<"4. Value: $"<<this->getValue()<<std::endl;
        std::cout<<"5. I am done editing. Go back."<<std::endl;
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
            std::cout<<"New address: ";
            std::cin.ignore();
            getline(std::cin, newBankName);
            address = newBankName;
            system("cls");
            break;
        case 3:

            while(!isValid){
                std::cout<<msg;
                std::cout<<"New rent: ";
                std::cin>>inp;
                if(utils.is_double(inp)){
                    isValid=true;
                    newRent = atof( inp.c_str() );
                    msg="";
                }else{
                    msg = "This is not a proper rent!\n";
                }
            }
            isValid=false;
            msg="";
            rent = newRent;
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

std::string RealEstate::serialize(){
    std::stringstream s;
    s << "-estate-" <<'\n'<< this->getName() << '\n' << this->getValue() << '\n' << this->getRent() << '\n' << this->getAddress()<<'\n';
    return s.str();
}

void RealEstate::deserialize(std::ifstream & myfile){
    char c;
    std::string line;
    double value,rent;
    getline (myfile,line);
    this->setName(line);
    myfile >> value;
    while (myfile.get(c) && c != '\n'){

    }

    myfile >> rent;
    while (myfile.get(c) && c != '\n'){
    }
    getline(myfile, line);
    this->setAddress(line);
    this->setValue(value);
    this->setRent(rent);
}

