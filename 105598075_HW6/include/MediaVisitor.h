#ifndef MEDIAVISITOR_H_INCLUDED
#define MEDIAVISITOR_H_INCLUDED

class ShapeMedia;
class combMedia;

//#include "ShapeMedia.h"
//#include "combMedia.h"

class MediaVisitor {

public:
    virtual void visitShapeMedia(ShapeMedia*) =0;
    virtual void visitCombMedia(combMedia*,bool) =0;
};

#endif // MEDIAVISITOR_H_INCLUDED
