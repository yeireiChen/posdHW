#ifndef DOCUMENT_H_INCLUDED
#define DOCUMENT_H_INCLUDED

#include <iostream>
class Document{

public:
    std::string openDocument(const std::string name){
        if(!canOpenDocument(name))
                throw std::string ("file is not existed");

        openFile(name);
        return readFile();
    }

protected:

    virtual void openFile(const std::string )=0;
    virtual bool canOpenDocument(const std::string)=0;
    virtual std::string readFile()=0;


};

#endif // DOCUMENT_H_INCLUDED
