#ifndef MEDIA_H_INCLUDED
#define MEDIA_H_INCLUDED


#include <iostream>
#include "MediaVisitor.h"
#include <vector>

class Media{

public:
    virtual double area() const=0;
    virtual double perimeter() const=0;
    virtual void accept(MediaVisitor*)=0;
    virtual std::string getName()const=0;
    virtual void setName(std::string)=0;

    virtual void add(Media*){
        throw std::string("Illegal: add on media");
    };

    virtual void removeMedia(Media* m){
        throw std::string("Illegal: remove on media");
    }

    virtual std::vector<Media*> getMediaP(){
        throw std::string("Illegal: remove on media");
    }

};

#endif // MEDIA_H_INCLUDED
