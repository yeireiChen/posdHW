#include "DescriptionVisitor.h"

DescriptionVisitor::DescriptionVisitor():dec(""){}

DescriptionVisitor::~DescriptionVisitor(){}

void DescriptionVisitor::visitShapeMedia(ShapeMedia* a){
    //std::cout << a->getShape()->getDec() << std::endl;
    dec+=a->getShape()->getDec();
}
void DescriptionVisitor::visitCombMedia(combMedia*,bool check){

    if(check)
        dec = dec + std::string("combo(");
    else
        dec = dec + std::string(")");
}

std::string DescriptionVisitor::getDescription()const{
    return dec;
}
