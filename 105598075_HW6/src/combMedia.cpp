
#include "combMedia.h"
#include <vector>
#include "DescriptionVisitor.h"
#include "traceVisitor.h"

using namespace std;

combMedia::combMedia():name(""){}

combMedia::~combMedia(){}

double combMedia::area()const{

    double temp=0;
    for(Media* a : cMedia){
        temp+=a->area();
    }

    return temp;
}

double combMedia::perimeter()const{

    double temp=0;
    for(Media* a : cMedia){
        temp+=a->perimeter();
    }

    return temp;
}

void combMedia::add(Media* a){

    cMedia.push_back(a);
}

void combMedia::accept(MediaVisitor* visit){
    visit->visitCombMedia(this,true);

    /*for (Media *m: cMedia)    //original cMedia is stack
            m->accept(visit);*/

    for(int i=0;i<cMedia.size();i++)
        cMedia.at(i)->accept(visit);

    visit->visitCombMedia(this,false);

}

std::vector<Media*> combMedia::getMediaP(){
    return cMedia;
}

std::string combMedia::getName() const{
    return name;
}

void combMedia::setName(std::string n){
    name = n;
}

void combMedia::removeMedia(Media* m){


    int index=0;
    for(int i=0;i<cMedia.size();i++){
        try{
            if(cMedia.at(i)==m){
                std::cout << "delete" << std::endl;
                //it = cMedia.at(i);
                cMedia.erase(cMedia.begin()+index);
            }
            else
                cMedia.at(i)->removeMedia(m);

        }catch(std::string a){
            continue;
        }
        index++;
    }
}

/*std::vector<Media*> combMedia::getMediaP(){

}*/


