#ifndef SETVALUEVISITOR_H
#define SETVALUEVISITOR_H

#include "Media.h"
#include "MediaVisitor.h"
#include "ShapeMedia.h"
#include "combMedia.h"
#include <queue>
#include <map>

class setValueVisitor:public MediaVisitor
{
    public:
        setValueVisitor(std::queue<std::string>*);
        virtual ~setValueVisitor();
        void visitShapeMedia(ShapeMedia*);
        void visitCombMedia(combMedia*,bool);

    protected:

    private:
        std::queue<std::string> *names;
};

#endif // SETVALUEVISITOR_H
