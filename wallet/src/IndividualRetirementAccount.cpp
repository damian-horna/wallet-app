#include "IndividualRetirementAccount.h"

IndividualRetirementAccount::IndividualRetirementAccount()
{
    //ctor
}

IndividualRetirementAccount::IndividualRetirementAccount(std::string b, double i, double amount)
{
    this->setName("IRA in "+b);
    this->setValue(amount);
    institution = b;
    interest = i;
}

std::string IndividualRetirementAccount::getInstitution(){
    return institution;
}

double IndividualRetirementAccount::simulate(){
    this->setValue(this->getValue() + ((interest/365)*this->getValue()));
    return this->getValue();
}
void IndividualRetirementAccount::showInfo(){
    std::cout<<"Name of asset: "<<this->getName()<<std::endl;
    std::cout<<"Name of institution: "<<this->getInstitution()<<std::endl;
    std::cout<<"Interest: "<<this->getInterest()<<std::endl;
    std::cout<<"Value: $"<<this->getValue()<<std::endl;
}
void IndividualRetirementAccount::edit(){
    bool exit = false;
    int propertyNumber;
    std::string newName, newBankName;
    double newInterest=0, newValue=0;

    while(!exit){
        std::cout<<"1. Name of asset: "<<this->getName()<<std::endl;
        std::cout<<"2. Name of institution: "<<this->getInstitution()<<std::endl;
        std::cout<<"3. Interest: "<<this->getInterest()<<std::endl;
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
            std::cout<<"New institution name: ";
            std::cin.ignore();
            getline(std::cin, newBankName);
            institution = newBankName;
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


double IndividualRetirementAccount::getInterest(){
    return interest;
}
void IndividualRetirementAccount::setInstitution(std::string b){
    institution = b;
}
void IndividualRetirementAccount::setInterest(double i){
    interest = i;
}

std::string IndividualRetirementAccount::serialize(){
    std::stringstream s;
    s << "-ira-" <<'\n'<< this->getName() << '\n' << this->getValue() << '\n' << this->getInterest() << '\n' << this->getInstitution()<<'\n';
    return s.str();
}

void IndividualRetirementAccount::deserialize(std::ifstream & myfile){
    char c;
    std::string line;
    double value,interest;
    getline (myfile,line);
    this->setName(line);
    myfile >> value;
    while (myfile.get(c) && c != '\n'){

    }

    myfile >> interest;
    while (myfile.get(c) && c != '\n'){
    }
    getline(myfile, line);
    this->setInstitution(line);
    this->setValue(value);
    this->setInterest(interest);
}
