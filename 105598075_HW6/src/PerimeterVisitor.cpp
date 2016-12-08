#include "PerimeterVisitor.h"


PerimeterVisitor::PerimeterVisitor():perimeter(0){}

PerimeterVisitor::~PerimeterVisitor(){}

void PerimeterVisitor::visitShapeMedia(ShapeMedia* visit){
    //visit->getShape()->showPerimeter();
    perimeter += visit->getShape()->perimeter();
}

void PerimeterVisitor::visitCombMedia(combMedia* visit,bool s){

}


double PerimeterVisitor::getPerimeter()const{

    return perimeter;
}
