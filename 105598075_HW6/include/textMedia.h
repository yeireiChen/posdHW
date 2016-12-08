#ifndef TEXTMEDIA_H
#define TEXTMEDIA_H

#include "Media.h"
#include "Text.h"
class textMedia:public Media
{
    public:
        textMedia(Text*);
        virtual ~textMedia();
        double area() const{}
        double perimeter() const{}
        void accept(MediaVisitor*){}
        Text* getText() const;
        std::string getName()const{}
        void setName(std::string){}


    protected:

    private:
        Text* txt;
};

#endif // TEXTMEDIA_H
