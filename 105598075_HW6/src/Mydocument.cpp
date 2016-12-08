#include "Mydocument.h"


Mydocument::Mydocument(){}

Mydocument::~Mydocument(){}



void Mydocument::openFile(const std::string name){

    ifs.open(name,std::ifstream::in);
}

bool Mydocument::canOpenDocument(const std::string name){

    ifs.open(name,std::ifstream::in);
    if (ifs.is_open()){
        ifs.close();
        return true;
    }
    else {
        ifs.close();
        return false;
    }
}

std::string Mydocument::readFile(){

    std::string str;
    getline(ifs,str);
    /*
    while (getline(ifs , str))
    {
        std::cout << str << std::endl;
    }*/
    return str;
}


