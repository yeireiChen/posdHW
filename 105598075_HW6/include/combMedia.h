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
        std::string getName() const;
        void setName(std::string);
        void removeMedia(Media* m);
        std::vector<Media*> getMediaP();


    protected:

    private:
        std::vector<Media*> cMedia;
        std::string name;
};

#endif // COMBMEDIA_H
