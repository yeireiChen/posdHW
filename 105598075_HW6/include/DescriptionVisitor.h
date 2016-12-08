#ifndef DESCRIPTIONVISITOR_H
#define DESCRIPTIONVISITOR_H

#include "MediaVisitor.h"
#include "ShapeMedia.h"
#include "combMedia.h"

class DescriptionVisitor:public MediaVisitor
{
    public:
        DescriptionVisitor();
        virtual ~DescriptionVisitor();
        void visitShapeMedia(ShapeMedia*);
        void visitCombMedia(combMedia*,bool);
        std::string getDescription()const;
    protected:

    private:
        std::string dec;
};

#endif // DESCRIPTIONVISITOR_H
