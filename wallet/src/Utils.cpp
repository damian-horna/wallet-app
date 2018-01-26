#include "Utils.h"

Utils::Utils()
{
    //ctor
}

bool Utils::is_number(const std::string& s)
{
   return s.find_first_not_of( "0123456789" ) == std::string::npos;
}

bool Utils::is_date(const std::string & s){
    std::regex pattern( "^[[:digit:]]+\\.[[:digit:]]+\\.[[:digit:]]+$" );
    std::smatch result;
    if(regex_search( s, result, pattern)){
        return true;
    }else return false;
}

bool Utils::is_double(const std::string &s){
    if(is_number(s)) return true;
    std::regex pattern( "^[0-9]+[^a-zA-z]+(\\.[0-9]+)?$" );
    std::smatch result;
    if(regex_search( s, result, pattern)){
        return true;
    }else return false;
}
