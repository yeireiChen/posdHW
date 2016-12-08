#ifndef MYDOCUMENT_H
#define MYDOCUMENT_H
#include "Document.h"
#include <fstream>

class Mydocument:public Document
{
    public:
        Mydocument();
        virtual ~Mydocument();
        //std::string openDocument(std::string );

    protected:
        void openFile(const std::string );
        bool canOpenDocument(const std::string );
        std::string readFile();

    private:
        std::ifstream ifs;

};

#endif // MYDOCUMENT_H
