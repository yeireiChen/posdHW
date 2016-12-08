#include "MediaDirector.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "TriangleC.h"
#include "combMediaBuilder.h"
#include "ShapeMediaBuilder.h"

#include "MediaVisitor.h"
#include "DescriptionVisitor.h"



using namespace std;

MediaDirector::MediaDirector(){}

MediaDirector::~MediaDirector(){}

void MediaDirector::setMediaBuilder(std::stack<MediaBuilder*> *mbs){

    mb=mbs;

}

void MediaDirector::concrete(std::string content){

    char tab2[1024];
    std::strcpy(tab2, content.c_str());
    /*for(int i=0;i<std::strlen(tab2);i++){ //show
        std::cout << tab2[i];
    }*/

    /****************************************************************************/

    std::string temp;
    std::string change;
    std::vector<std::string> vsequence;
    /*************/

    for(int i=0;i<strlen(tab2);i++){    //split command

        if(tab2[i]==' ' && tab2[i-1]==')')
            continue;
        else
            temp+=tab2[i];


        if (tab2[i]=='('){
            vsequence.push_back(temp);
            temp.clear();
        }
        else if (tab2[i]==')' && tab2[i+1]==' '){ //tab2[i]==')' && tab2[i+1]==' '
            change = vsequence.back()+temp;
            vsequence.pop_back();
            vsequence.push_back(change);
            temp.clear();
        }
        else if(tab2[i]==')'){
            vsequence.push_back(temp);
            temp.clear();
        }


    }


    /*std::cout << "vsequence_________________________________________________________" <<std::endl;

    for(int i=0;i<vsequence.size();i++){    //show
       std::cout << vsequence.at(i)<<std::endl;
    }

    std::cout << "_________________________________________________________" <<std::endl;*/


    std::vector<std::string> num2 ;
    int length;
    int ntemp=0;//delete
    DescriptionVisitor t; //delete

    for(int i=0;i<vsequence.size();i++){

        if(vsequence.at(i).compare("combo(")==0){

            mb->push(new combMediaBuilder());
            mb->top()->buildComboMedia();
        }
        else if (vsequence.at(i).compare(")")==0){
            if(i==vsequence.size()-1){  //final )
                //std::cout << i << " is "<< vsequence.at(i) <<std::endl;
            }
            else{   //else comb('s --->)
                //std::cout << vsequence.at(i) <<std::endl;

                Media *s=mb->top()->getMedia();
                mb->pop();
                mb->top()->buildAddComboMedia(s);
            }
        }
        else{
            length = vsequence.at(i).length();
            temp = vsequence.at(i).substr(2,length-3);  //split number
            //std::cout << "..."<<temp <<std::endl;
            double a,b,c,d,e,f;
            std::stringstream ss(temp);//start
            /*
            while (ss >> temp)
                num2.push_back(temp);  //end to split white space_(10 0 2)->10,0,2
            */

            if(vsequence.at(i).at(0)=='r'){ //combMediaBuilder::buildShapeMedia(Shape* t)       Rectangle(double,double,double,double);
                //std::cout << "r(" <<num2.at(0)<<" "<<num2.at(1)<<" "<<num2.at(2)<<" "<<num2.at(3)<<")"<<std::endl;
                //Rectangle *r =new Rectangle(atof(num2.at(0).c_str()),atof(num2.at(1).c_str()),atof(num2.at(2).c_str()),atof(num2.at(3).c_str()));

                ss >>a>>b>>c>>d;
                Rectangle *rec =new Rectangle(a,b,c,d);
                mb->top()->buildShapeMedia(rec);

            }else if(vsequence.at(i).at(0)=='c'){   //Circle(double ,double ,double );
                //std::cout << "c(" <<num2.at(0)<<" "<<num2.at(1)<<" "<<num2.at(2)<<")"<<std::endl;
                //Circle* c=new Circle(atof(num2.at(0).c_str()),atof(num2.at(1).c_str()),atof(num2.at(2).c_str()));
                ss >>a>>b>>c;
                Circle *cir =new Circle(a,b,c);
                mb->top()->buildShapeMedia(cir);

            }else if (vsequence.at(i).at(0)=='t'){  //Triangle(double,double,double,double,double,double);
                //Triangle* c=new Triangle(atof(num2.at(0).c_str()),atof(num2.at(1).c_str()),atof(num2.at(2).c_str()),atof(num2.at(3).c_str()),atof(num2.at(4).c_str()),atof(num2.at(5).c_str()));
                ss >>a>>b>>c>>d>>e>>f;
                Triangle *tri =new Triangle(a,b,c,d,e,f);
                mb->top()->buildShapeMedia(tri);


            }

            num2.clear();//initialize number vector

        }


    }//end for


}

void MediaDirector::buildComb(std::vector<Media*> *n,MediaBuilder *s){
    s->buildComboMedia();
    for(int i=0;i<n->size();i++){
        s->buildAddComboMedia(n->at(i));
    }
}
void MediaDirector::buildShpae(std::string content,std::vector<std::string> *n,MediaBuilder* s){    //def a = Triangle(0,0,1,0,1,0)
    //std::cout << "creater is " << content << std::endl;
    if (content.compare("Circle")==0 && n->size()==3){
        //std::cout << "prepare to create Circle" << std::endl;
        Circle *c = new Circle(atof(n->at(0).c_str()),atof(n->at(1).c_str()),atof(n->at(2).c_str()));
        s->buildShapeMedia(c);
    }else if (content.compare("Rectangle")==0 && n->size()==4){
        //std::cout << "prepare to create Rectangle" << std::endl;
        Rectangle *c = new Rectangle(atof(n->at(0).c_str()),atof(n->at(1).c_str()),atof(n->at(2).c_str()),atof(n->at(3).c_str()));
        s->buildShapeMedia(c);
    }else if(content.compare("Triangle")==0 && n->size()==6){
        //std::cout << "prepare to create Traingle" << std::endl;
        try{
            //Triangle *c = new Triangle(atof(n->at(0).c_str()),atof(n->at(1).c_str()),atof(n->at(2).c_str()),atof(n->at(3).c_str()),atof(n->at(4).c_str()),atof(n->at(5).c_str()));
            TriangleC c = TriangleC::create(atof(n->at(0).c_str()),atof(n->at(1).c_str()),atof(n->at(2).c_str()),atof(n->at(3).c_str()),atof(n->at(4).c_str()),atof(n->at(5).c_str()));
            s->buildShapeMedia(&c);
        }catch(std::string s){
            //std::cout << s <<std::endl;
            throw s;
        }

    }else{
        std::cout << "error type" << std::endl;
    }

}
