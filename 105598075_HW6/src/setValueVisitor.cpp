#include "setValueVisitor.h"
typedef std::pair<std::string, Media*> MyPair;

setValueVisitor::setValueVisitor(std::queue<std::string> *b,std::map<std::string,Media*> *c){
    names=b;
    nMap=c;
}

setValueVisitor::~setValueVisitor(){}


void setValueVisitor::visitShapeMedia(ShapeMedia* a){
    a->setName(names->front());
    nMap->insert(MyPair(names->front(),a));
    //std::cout << names->front() << std::endl;
    names->pop();
}
void setValueVisitor::visitCombMedia(combMedia* a,bool check){

    if(check){
        a->setName(names->front());
        nMap->insert(MyPair(names->front(),a)); //insert to MAp
        //std::cout << names->front() << std::endl;
        names->pop();
    }
}
