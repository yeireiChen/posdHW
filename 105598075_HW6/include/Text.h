#ifndef TEXT_H
#define TEXT_H

#include "Rectangle.h"
#include "Shape.h"
#include "Media.h"

class Text
{
    public:
        Text(Shape*,std::string);
        Text(Media*,std::string);
        virtual ~Text();
        std::string getInformation()const;

    protected:

    private:
        std::string information;
        Shape* sh;
        Media* med;
};

#endif // TEXT_H
