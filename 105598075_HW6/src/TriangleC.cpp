#include "TriangleC.h"

#include <iostream>

using namespace std;

TriangleC::TriangleC(double firX,double firY,double secX,double secY,double thirdX,double thirdY):fx(firX),fy(firY),sx(secX),sy(secY),tx(thirdX),ty(thirdY),t(false),shapeName("Triangle"){

        t=true;
        //std::cout << "3 points create a triangle" <<std::endl;
        fWidth = sqrt(pow(fx-sx,2)+pow(fy-sy,2));
        //std::cout << "width between first and two is " << fWidth <<std::endl;
        sWidth = sqrt(pow(fx-tx,2)+pow(fy-ty,2));
        //std::cout << "width between first and third is " << sWidth <<std::endl;
        tWidth = sqrt(pow(sx-tx,2)+pow(sy-ty,2));
        //std::cout << "width between swcond and third is " << tWidth <<std::endl;

}

TriangleC::~TriangleC(){}

TriangleC TriangleC::create(double firX,double firY,double secX,double secY,double thirdX,double thirdY){
    if(firX==secX && firX==thirdX && secX==thirdX)
    {
        //std::cout << "3 points at a xline" <<std::endl;
        throw std::string ("3 points at a xline");

    }
    else if (firY==secY && firY==thirdY && secY==thirdY)
    {
        //std::cout << "3 points at a yline" <<std::endl;
        throw std::string ("3 points at a yline");
    }
    else if ( (firX-secX)/(firY-secY) == (firX-thirdX)/(firY-thirdY) )
    {
        //std::cout << "3 points at a same line" <<std::endl;
        throw std::string ("3 points at a same line");
    }
    else if (firX==secX && firX==thirdX && secX==thirdX && firY==secY && firY==thirdY && secY==thirdY)
    {
        //std::cout << "3 points are same" <<std::endl;
        throw std::string ("3 points are same");
    }
    else if (firX==secX && firY==secY)
    {
        //std::cout << "first point and second point are same" <<std::endl;
        throw std::string ("first point and second point are same");
    }
    else if (firX==thirdX && firY==thirdY)
    {
        //std::cout << "first point and third point are same" <<std::endl;
        throw std::string ("first point and third point are same");
    }
    else if (secX==thirdX && secY==thirdY)
    {
        //std::cout << "second point and third point are same" <<std::endl;
        throw std::string ("second point and third point are same");
    }
     else{

        return TriangleC(firX,firY,secX,secY,thirdX,thirdY);
     }
}

double TriangleC::area() const{

    double temp=0;
    temp = (fWidth+sWidth+tWidth)/2;



    return sqrt( temp*(temp-fWidth)*(temp-sWidth)*(temp-tWidth));
}

double TriangleC::perimeter() const{

    return (fWidth+sWidth+tWidth);
}

bool TriangleC::getSuccess() const{
    return t;
}

void TriangleC::showArea()const{

    double temp=0;
    temp = (fWidth+sWidth+tWidth)/2;
    cout<< "Triangle Area is " << sqrt( temp*(temp-fWidth)*(temp-sWidth)*(temp-tWidth)) <<endl;
}

void TriangleC::showPerimeter()const{
    cout<< "Triangle Perimeter is " << (fWidth+sWidth+tWidth) <<endl;
}

string TriangleC::getShapeN() const {return shapeName;}

string TriangleC::getDec() const {

    stringstream ss;
    //ss << "r(" << x << " " << y << " " << l << " " << w << ") ";
    ss << "t(" << fx << " " << fy << " " << sx << " " << sy << " " << tx << " " << ty << ") ";

    return ss.str();
}

std::string TriangleC::getFullDec() const{

    stringstream ss;
    ss << "t(" << fx << "," << fy << "," << sx << "," << sy << "," << tx << "," << ty << ") ";
    return ss.str();
}
