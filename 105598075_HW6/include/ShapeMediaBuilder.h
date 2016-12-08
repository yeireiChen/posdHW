#ifndef SHAPEMEDIABUILDER_H
#define SHAPEMEDIABUILDER_H

#include <MediaBuilder.h>

class ShapeMediaBuilder:public MediaBuilder
{
    public:
        ShapeMediaBuilder();
        virtual ~ShapeMediaBuilder();
        void buildComboMedia();
        void buildShapeMedia(Shape*);
        Media* getMedia();
        void buildAddComboMedia(Media*);

    private:
        ShapeMedia* shapes;
};

#endif // SHAPEMEDIABUILDER_H
