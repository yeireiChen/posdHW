#ifndef COMBMEDIABUILDER_H
#define COMBMEDIABUILDER_H

#include <MediaBuilder.h>
#include <combMedia.h>

class combMediaBuilder:public MediaBuilder
{
    public:
        combMediaBuilder();
        virtual ~combMediaBuilder();

        void buildComboMedia();
        void buildShapeMedia(Shape*);
        combMedia* getMedia();

        void buildAddComboMedia(Media*);
    protected:

    private:
        combMedia* combo;
};

#endif // COMBMEDIABUILDER_H
