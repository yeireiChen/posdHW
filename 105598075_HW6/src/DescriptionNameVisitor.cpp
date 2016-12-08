#include "DescriptionNameVisitor.h"

DescriptionNameVisitor::DescriptionNameVisitor():dec(""){}

DescriptionNameVisitor::~DescriptionNameVisitor(){}

void DescriptionNameVisitor::visitShapeMedia(ShapeMedia* a){
    //std::cout << a->getShape()->getDec() << std::endl;
    dec+=a->getName()+" ";
}
void DescriptionNameVisitor::visitCombMedia(combMedia* a,bool check){

    if(check)
        dec = dec + a->getName()+std::string("{");
    else
        dec = dec + std::string("}");
}

std::string DescriptionNameVisitor::getDescription()const{
    return dec;
}
