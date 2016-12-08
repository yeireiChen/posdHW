#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Shape {
public:
    virtual std::string getShapeN() const =0;
    virtual double area() const = 0;
    virtual double perimeter() const =0;
    //virtual void showArea() const{}
    //virtual void showPerimeter()const{}
    virtual std::string getDec() const=0;
    virtual std::string getFullDec() const=0;
};



/*static double sumOfPerimeter(std::vector<Shape *> shps){

    double total =0;
    for (Shape *r: shps)
        total += r->perimeter();
    return total;

}

static double sumOfArea(std::vector<Shape*> shps){

    double total=0;
    for(Shape *r:shps)
        total += r->area();

    return total;
}



static void maxArea(std::vector<Shape*> shps){

    double max=0;
    Shape *temp;
    for(Shape *r:shps){
        if (r->area() > max){
            max = r->area();
            temp = r;
        }
        else
            continue;
    }

    std::cout << "maxArea is " << temp->getShapeN() <<" , and it is " << temp->area() <<std::endl;

}


static void showV(std::vector<Shape *> shps){

    for(Shape *p : shps){

        std::cout << p->perimeter() <<"__";
    }

    std::cout << std::endl;
}

static bool comp(Shape* a,Shape* b){
    return (a->perimeter() > b->perimeter());
}

static void sortByD(std::vector<Shape *> &shps){
    sort(shps.begin(),shps.end(),comp);

}
*/
#endif // SHAPE_H_INCLUDED
