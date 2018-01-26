#include "Asset.h"

std::string Asset::getName(){
    return name;
}
void Asset::setName(std::string n){
    name = n;
}
double Asset::getValue(){
    return value;
}
void Asset::setValue(double p){
    value = p;
}
