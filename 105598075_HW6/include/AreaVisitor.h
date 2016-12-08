#ifndef AREAVISITOR_H
#define AREAVISITOR_H


#include "MediaVisitor.h"
#include "ShapeMedia.h"
#include "combMedia.h"

class AreaVisitor:public MediaVisitor
{
    public:
        AreaVisitor();
        virtual ~AreaVisitor();

        void visitShapeMedia(ShapeMedia*);
        void visitCombMedia(combMedia*,bool);

        double getArea() const;


    protected:

    private:
        double area;
};
#endif // AREAVISITOR_H
