#ifndef DESCRIPTIONNAMEVISITOR_H
#define DESCRIPTIONNAMEVISITOR_H

#include "MediaVisitor.h"
#include "ShapeMedia.h"
#include "combMedia.h"

class DescriptionNameVisitor:public MediaVisitor
{
    public:
        DescriptionNameVisitor();
        virtual ~DescriptionNameVisitor();
        void visitShapeMedia(ShapeMedia*);
        void visitCombMedia(combMedia*,bool);
        std::string getDescription()const;

    protected:

    private:
        std::string dec;
};

#endif // DESCRIPTIONNAMEVISITOR_H
