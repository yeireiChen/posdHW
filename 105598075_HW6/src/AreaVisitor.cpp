#include "AreaVisitor.h"

AreaVisitor::AreaVisitor():area(0){}

AreaVisitor::~AreaVisitor(){}


void AreaVisitor::visitShapeMedia(ShapeMedia* visit){
    //visit->getShape()->showArea();
    area += visit->getShape()->area();
}

void AreaVisitor::visitCombMedia(combMedia* visit,bool s){

}


double AreaVisitor::getArea()const{

    return area;
}

