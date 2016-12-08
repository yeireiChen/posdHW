
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



std::string combMedia::getName() const{
    return name;
}

void combMedia::setName(std::string n){
    name = n;
}

void combMedia::removeMedia(Media* t)const{


    DescriptionVisitor ds;
    t->accept(&ds);
    std::string deletxt = ds.getDescription();
    //std::cout << deletxt << std::endl;

    traceVisitor t1(deletxt);

    int i=0;
    //t1.visitCombMedia(this,true);
    for (Media* m:cMedia){

            //i = &m-&cMedia[0];
            m->accept(&t1);

            /*
            if(t1.findOut()){
                std::cout << "find out at"<< i <<std::endl;
                //cMedia.erase(cMedia.begin()+i);
                //cMedia.erase(std::remove(cMedia.begin(), cMedia.end(), m), cMedia.end());
            }
            else{
                std::cout << "Not find out" <<std::endl;
                i++;
            }*/

            //std::cout << "____________" <<std::endl;


    }

    /*
    for (Media *m: cMedia){

            m->accept(&t1);
            if(t1.findOut()){
                std::cout << "find out at"<< i <<std::endl;
                cMedia.erase(std::remove(cMedia.begin(), cMedia.end(), m), cMedia.end());
            }
            else{
                std::cout << "Not find out" <<std::endl;
                i++;
            }
    }



    */
/*
    DescriptionVisitor visit;

    for (Media *m: cMedia){
            m->accept(&visit);
            std::cout << visit.getDescription() << std::endl;
    }*/
}
