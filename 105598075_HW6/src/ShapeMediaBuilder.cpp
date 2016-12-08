#include "ShapeMediaBuilder.h"

ShapeMediaBuilder::ShapeMediaBuilder():shapes(0){}

ShapeMediaBuilder::~ShapeMediaBuilder(){}

void ShapeMediaBuilder::buildComboMedia(){}

void ShapeMediaBuilder::buildShapeMedia(Shape* t){

    shapes = new ShapeMedia(t);
}

Media* ShapeMediaBuilder::getMedia(){

    return shapes;
}
void ShapeMediaBuilder::buildAddComboMedia(Media*){
}

