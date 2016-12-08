#ifndef TRACEVISITOR_H
#define TRACEVISITOR_H

#include "MediaVisitor.h"
#include "ShapeMedia.h"
#include "combMedia.h"

class traceVisitor:public MediaVisitor
{
    public:
        traceVisitor(std::string);
        virtual ~traceVisitor();
        void visitShapeMedia(ShapeMedia*);
        void visitCombMedia(combMedia*,bool);
        bool findOut()const;

    protected:

    private:
        std::string deletext;
        bool findO;
};

#endif // TRACEVISITOR_H
