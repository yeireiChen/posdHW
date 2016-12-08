#include "setValueVisitor.h"
typedef std::pair<std::string, Media*> MyPair;

setValueVisitor::setValueVisitor(std::queue<std::string> *b){
    names=b;

    /*for(int i=0;i<=names->size();i++){
        std::cout << names->front() << std::endl;
        names->pop();
    }*/
}

setValueVisitor::~setValueVisitor(){}


void setValueVisitor::visitShapeMedia(ShapeMedia* a){
    a->setName(names->front());
    //std::cout << names->front() << std::endl;
    names->pop();
}
void setValueVisitor::visitCombMedia(combMedia* a,bool check){

    if(check){
        a->setName(names->front());
        //std::cout << names->front() << std::endl;
        names->pop();
    }

    /*if(check)
        dec = dec + std::string("combo(");
    else
        dec = dec + std::string(")");*/
}
//std::map<std::string,Media*> *namesMap;
//std::queue<std::string> *names;
