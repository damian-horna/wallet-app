#include "Contract.h"

Contract::Contract(){
}

Contract::Contract(std::string name, double m, double amount){
    this->setName(name);
    this->setValue(amount);
    multiplier = m;
}

double Contract::getMultiplier(){
    return multiplier;
}

void Contract::setMultiplier(double m){
    multiplier = m;
}

double Contract::simulate(){
    if(((((rand() % 10) + 1 ) % 2) == 0) && (this->getValue() - multiplier) > 0){
        this->setValue(this->getValue() - multiplier);
    }else this->setValue(this->getValue() + multiplier);
    return this->getValue();
}
void Contract::showInfo(){
    std::cout<<"Name of asset: "<<this->getName()<<std::endl;
    std::cout<<"Multiplier: "<<this->getMultiplier()<<std::endl;
    std::cout<<"Value: $"<<this->getValue()<<std::endl;
}
void Contract::edit(){
    bool exit = false;
    int propertyNumber;
    std::string newName;
    double newValue=0, newMultiplier=0;

    while(!exit){
        std::cout<<"1. Name of Contract: "<<this->getName()<<std::endl;
        std::cout<<"2. Multiplier: "<<this->getMultiplier()<<std::endl;
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
            std::cout<<"New contract name: ";
            std::cin.ignore();
            getline(std::cin, newName);
            this->setName(newName);
            system("cls");
            break;
        case 2:
            while(!isValid){
                std::cout<<msg;
                std::cout<<"New multiplier: ";
                std::cin>>inp;
                if(utils.is_double(inp)){
                    isValid=true;
                    newMultiplier = atof( inp.c_str() );
                    msg="";
                }else{
                    msg = "This is not a proper multiplier!\n";
                }
            }
            isValid=false;
            msg="";
            multiplier = newMultiplier;
            this->setMultiplier(newMultiplier);
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

std::string Contract::serialize(){
    std::stringstream s;
    s << "-contract-" <<'\n'<< this->getName() << '\n' << this->getValue() << '\n' << this->getMultiplier()<<'\n';
    return s.str();
}

void Contract::deserialize(std::ifstream & myfile){
    char c;
    std::string line;
    double value,multiplier;
    getline (myfile,line);
    this->setName(line);
    myfile >> value;
    while (myfile.get(c) && c != '\n'){

    }
    myfile >> multiplier;
    while (myfile.get(c) && c != '\n'){
    }
    this->setValue(value);
    this->setMultiplier(multiplier);
}
