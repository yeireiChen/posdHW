#include "ShapeMedia.h"

ShapeMedia::ShapeMedia(Shape* s):shape(s),name(""){}

ShapeMedia::~ShapeMedia(){}

double ShapeMedia::area()const{
    return shape->area();
}

double ShapeMedia::perimeter()const{
    return shape->perimeter();
}

Shape* ShapeMedia::getShape()const{
    return shape;
}

void ShapeMedia::accept(MediaVisitor* visit){
    visit->visitShapeMedia(this);
}

std::string ShapeMedia::getName() const{
    return name;
}

void ShapeMedia::setName(std::string n){
    name = n;
}
