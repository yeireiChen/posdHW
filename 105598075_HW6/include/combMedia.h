#ifndef COMBMEDIA_H
#define COMBMEDIA_H


#include <vector>
#include "Media.h"

class combMedia:public Media
{
     public:
        combMedia();
        virtual ~combMedia();
        double area() const;
        double perimeter() const;
        void accept(MediaVisitor*);
        void add(Media*);
        void removeMedia(Media*)const;
        std::string getName() const;
        void setName(std::string);

    protected:

    private:
        std::vector<Media*> cMedia;
        std::string name;
};

#endif // COMBMEDIA_H
