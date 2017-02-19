#include <iostream>
#include "a.h"


MySample::MySample():a(0){
        b=1;
        MySample::initSample();
        MySample::initD();
        // c=1;
};

void
MySample::initSample(){
    c=1;
}

void
MySample::print(){
    std::cout<<"a:"<<a<<std::endl;
    std::cout<<"b:"<<b<<std::endl;
    std::cout<<"c:"<<c<<std::endl;
    std::cout<<"d:"<<d<<std::endl;
    std::cout<<"e:"<<d<<std::endl;
}

int
main(){
    MySample s;
    s.print();
    return 0;
}
