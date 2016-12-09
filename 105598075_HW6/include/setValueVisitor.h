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
        setValueVisitor(std::queue<std::string>*,std::map<std::string,Media*>*);
        virtual ~setValueVisitor();
        void visitShapeMedia(ShapeMedia*);
        void visitCombMedia(combMedia*,bool);

    protected:

    private:
        std::queue<std::string> *names;
        std::map<std::string,Media*> *nMap;
};

#endif // SETVALUEVISITOR_H
