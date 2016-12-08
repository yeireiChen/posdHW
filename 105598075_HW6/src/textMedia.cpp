#include "textMedia.h"

textMedia::textMedia(Text* t):txt(t){}

textMedia::~textMedia(){}

Text* textMedia::getText()const{
    return txt;
}

