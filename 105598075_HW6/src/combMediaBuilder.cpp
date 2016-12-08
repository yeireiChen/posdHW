#include "combMediaBuilder.h"


combMediaBuilder::combMediaBuilder():combo(0){}

combMediaBuilder::~combMediaBuilder(){}

void combMediaBuilder::buildComboMedia(){
    combo = new combMedia();
}

void combMediaBuilder::buildShapeMedia(Shape* t){
    if(!combo)
            throw std::string("null point ex") ;
        combo->add(new ShapeMedia(t));
}

void combMediaBuilder::buildAddComboMedia(Media * cm){
        combo->add(cm);
}

combMedia* combMediaBuilder::getMedia(){

    return combo;
}
