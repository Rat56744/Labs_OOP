#include "stdfax.h"

class Error:public std::exception
{
private:
    string str;
public:
    string get_str()const{return str;}
    
    Error(string err):str(err){};
    
    Error& operator=(const Error& a){
        str = a.get_str();
        return *this;}

    const char* what() const noexcept override {return str.c_str();}
};