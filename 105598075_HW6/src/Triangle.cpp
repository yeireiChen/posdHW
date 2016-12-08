#include "Triangle.h"

#include <iostream>

using namespace std;

Triangle::Triangle(double firX,double firY,double secX,double secY,double thirdX,double thirdY):fx(firX),fy(firY),sx(secX),sy(secY),tx(thirdX),ty(thirdY),t(false),shapeName("Triangle"){

    if(fx==sx && fx==tx && sx==tx){
            std::cout << "3 points at a xline" <<std::endl;
            }
        else if (fy==sy && fy==ty && sy==ty){
            std::cout << "3 points at a yline" <<std::endl;
            }
        else if ( (fx-sx)/(fy-sy) == (fx-tx)/(fy-ty) ){
            std::cout << "3 points at a same line" <<std::endl;
            }
        else if (fx==sx && fx==tx && sx==tx && fy==sy && fy==ty && sy==ty){
            std::cout << "3 points are same" <<std::endl;
            }
        else if (fx==sx && fy==sy){
            std::cout << "first point and second point are same" <<std::endl;
            }
        else if (fx==tx && fy==ty){
            std::cout << "first point and third point are same" <<std::endl;
            }
        else if (sx==tx && sy==ty){
            std::cout << "second point and third point are same" <<std::endl;
            }
     else{

        t=true;
        //std::cout << "3 points create a triangle" <<std::endl;
        fWidth = sqrt(pow(fx-sx,2)+pow(fy-sy,2));
        //std::cout << "width between first and two is " << fWidth <<std::endl;
        sWidth = sqrt(pow(fx-tx,2)+pow(fy-ty,2));
        //std::cout << "width between first and third is " << sWidth <<std::endl;
        tWidth = sqrt(pow(sx-tx,2)+pow(sy-ty,2));
        //std::cout << "width between swcond and third is " << tWidth <<std::endl;

     }
}

Triangle::~Triangle(){}

double Triangle::area() const{

    double temp=0;
    temp = (fWidth+sWidth+tWidth)/2;



    return sqrt( temp*(temp-fWidth)*(temp-sWidth)*(temp-tWidth));
}

double Triangle::perimeter() const{

    return (fWidth+sWidth+tWidth);
}

bool Triangle::getSuccess() const{
    return t;
}

void Triangle::showArea()const{

    double temp=0;
    temp = (fWidth+sWidth+tWidth)/2;
    cout<< "Triangle Area is " << sqrt( temp*(temp-fWidth)*(temp-sWidth)*(temp-tWidth)) <<endl;
}

void Triangle::showPerimeter()const{
    cout<< "Triangle Perimeter is " << (fWidth+sWidth+tWidth) <<endl;
}

string Triangle::getShapeN() const {return shapeName;}

string Triangle::getDec() const {

    stringstream ss;
    //ss << "r(" << x << " " << y << " " << l << " " << w << ") ";
    ss << "t(" << fx << " " << fy << " " << sx << " " << sy << " " << tx << " " << ty << ") ";

    return ss.str();
}

std::string Triangle::getFullDec() const{

    stringstream ss;
    ss << "t(" << fx << "," << fy << "," << sx << "," << sy << "," << tx << "," << ty << ") ";
    return ss.str();
}

