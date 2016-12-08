#include "traceVisitor.h"

traceVisitor::traceVisitor(std::string s):deletext(s),findO(false){}

traceVisitor::~traceVisitor(){}

void traceVisitor::visitShapeMedia(ShapeMedia* s){
    /*
    if(s->getShape()->getDec() == deletext)
        findO=true;*/
        //std::cout << s->getShape()->getDec() <<std::endl;
        if(s->getShape()->getDec() == deletext)
            findO = true;
}
void traceVisitor::visitCombMedia(combMedia*,bool) {}


bool traceVisitor::findOut()const{
    return findO;
}
