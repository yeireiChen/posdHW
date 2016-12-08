#include "Text.h"

Text::Text(Shape* r,std::string s):sh(r),information(s){}
Text::Text(Media* m,std::string s):med(m),information(s){}

Text::~Text(){}

std::string Text::getInformation()const{
    return information;
}
