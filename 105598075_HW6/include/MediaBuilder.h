#ifndef MEDIABUILDER_H_INCLUDED
#define MEDIABUILDER_H_INCLUDED

#include<Shape.h>
#include<ShapeMedia.h>
#include<combMedia.h>

class MediaBuilder{

public:
    virtual void buildComboMedia()=0;
    virtual void buildShapeMedia(Shape*)=0;
    virtual Media* getMedia()=0;

    virtual void buildAddComboMedia(Media*)=0;
};

#endif // MEDIABUILDER_H_INCLUDED
