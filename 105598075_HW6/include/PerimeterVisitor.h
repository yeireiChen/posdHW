#ifndef PERIMETERVISITOR_H
#define PERIMETERVISITOR_H


#include "MediaVisitor.h"
#include "ShapeMedia.h"
#include "combMedia.h"

class PerimeterVisitor:public MediaVisitor
{
    public:
        PerimeterVisitor();
        virtual ~PerimeterVisitor();

        void visitShapeMedia(ShapeMedia*);
        void visitCombMedia(combMedia*,bool);

        double getPerimeter() const;
    protected:

    private:
        double perimeter;
};

#endif // PERIMETERVISITOR_H
