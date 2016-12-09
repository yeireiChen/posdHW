#ifndef UTSHAPES_H_INCLUDED
#define UTSHAPES_H_INCLUDED

#include "..\cppunitlite\TestHarness.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "combShape.h"
#include "ShapeMedia.h"
#include "combMedia.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"
#include "ShapeMediaBuilder.h"
#include "combMediaBuilder.h"
#include "descriptionVisitor.h"
#include "Text.h"
#include "TextMedia.h"
#include "Mydocument.h"
#include "MediaDirector.h"

#include <vector>
#include <iostream>

const double epsilon = 0.01;
// added this line


TEST(first,Circle)
{
    Circle circ(0,0,10);
    //DOUBLES_EQUAL(60,circ.perimeter(),epsilon);
}


TEST(second,Rectangle)
{
    Rectangle rect(0,0,4,2);
    //DOUBLES_EQUAL(12,rect.perimeter(),epsilon);
}

TEST(third,Triangle)
{
    Triangle tria(0,0,3,4,3,-4); //error test_00,34,-3-4__at same line,it can't form a triangle
    CHECK(tria.getSuccess());
}

TEST(fourth,Triangle)
{
    Triangle tria(0,0,3,4,3,-4);
    //DOUBLES_EQUAL(18,tria.perimeter(),epsilon);
}

TEST(fifth,Triangle)    /*area of tirangle*/
{
    Triangle tria(0,0,3,0,0,4);
    //DOUBLES_EQUAL(6,tria.area(),epsilon);   //error test
}

TEST (sixth, sumOfPerimeter) {
    Rectangle r1(0,0,4,2);  //0042-12
    Circle c1(0,0,10);  //00.10-60(pi=3)
    Triangle t1(0,0,3,0,0,4);   //003004-12
    std::vector<Shape *> ss;
    ss.push_back(&r1);
    ss.push_back(&c1);
    ss.push_back(&t1);
    //DOUBLES_EQUAL(84,sumOfPerimeter(ss),epsilon);
}


/*___________________HW2______________________________*/



TEST (seven, maxArea) {
    Rectangle r1(0,0,4,2);  //8
    Circle c1(0,0,2);  //12
    Circle c2(1,1,10);  //300
    Triangle t1(0,0,0,3,4,0);   //6
    std::vector<Shape *> ss;
    ss.push_back(&r1);
    ss.push_back(&c1);
    ss.push_back(&c2);
    ss.push_back(&t1);
    //maxArea(ss);

}

TEST(eighth,sorByDecreaingPerimeter){

    Rectangle r1(0,0,3,2);  //10
    Circle c1(0,0,10);  //60
    Circle c2(1,1,20);  //120
    Triangle t1(0,0,3,0,0,4);   //12
    std::vector<Shape *> ss;
    ss.push_back(&r1);
    ss.push_back(&c1);
    ss.push_back(&c2);
    ss.push_back(&t1);

    //showV(ss);
    //sortByD(ss);
    //showV(ss);
    //std::cout << std::endl;

}

TEST(ninth,combShapePerimeter){

    Rectangle r1(0,0,3,2);  //10
    Circle c1(0,0,10);  //60
    Circle c2(1,1,20);  //120
    Triangle t1(0,0,3,0,0,4);   //12
    std::vector<Shape *> s1;
    s1.push_back(&r1);
    s1.push_back(&c1);
    s1.push_back(&c2);
    s1.push_back(&t1);

    combShape s2;
    s2.add(s1);

    //DOUBLES_EQUAL(202,s2.perimeter(),epsilon);  //should be 202
    //std::cout << s2.perimeter() <<std::endl;


}

TEST(tenth,combShapeArea){

    Rectangle r1(0,0,3,2);  //6
    Circle c1(0,0,10);  //300
    Circle c2(1,1,5);  //75
    Triangle t1(0,0,3,0,0,4);   //6
    std::vector<Shape *> s1;
    s1.push_back(&r1);
    s1.push_back(&c1);
    s1.push_back(&c2);
    s1.push_back(&t1);

    combShape s2;
    s2.add(s1);

    //DOUBLES_EQUAL(387,s2.area(),epsilon);   //should be 387
    //std::cout << s2.perimeter() <<std::endl;



}

/*___________________HW3______________________________*/


TEST(eleven,combMediaArea){

    /*
    Circle c1(0,0,10);  //300
    Triangle t1(0,0,3,0,0,4);   //6

    ShapeMedia s(&c1);
    ShapeMedia s1(&t1);

    combMedia com1;
    com1.add(&s);
    com1.add(&s1);
    DOUBLES_EQUAL(6,s1.area(),epsilon);
    DOUBLES_EQUAL(306,com1.area(),epsilon);

    Rectangle r1(0,3.46,3.46,2); //double ulcx, double ulcy, double length, double width
    DOUBLES_EQUAL(6.92,r1.area(),epsilon);
    */

    Triangle tri1(-1,1.73,0,0,0,3.46);//double firX,double firY,double secX,double secY,double thirdX,double thirdY
    Triangle tri2(2,0,2,3.46,3,1.73);
    //std::cout << tri1.perimeter() <<std::endl;
    //DOUBLES_EQUAL(7.41,tri1.perimeter(),epsilon);
    Rectangle rec1(0,3.46,3.46,2); //double ulcx, double ulcy, double length, double width

    ShapeMedia sh1(&tri1);
    ShapeMedia sh2(&tri2);
    ShapeMedia sh3(&rec1);

    combMedia comb1;
    comb1.add(&sh1);
    comb1.add(&sh2);
    comb1.add(&sh3);
    //std::cout << comb1.area() <<std::endl;
    DOUBLES_EQUAL(10.38,comb1.area(),epsilon);      //10.38





}

TEST(eleven,combMediaPerimeter){

    Triangle tri1(-1,1.73,0,0,0,3.46);//double firX,double firY,double secX,double secY,double thirdX,double thirdY
    Triangle tri2(2,0,2,3.46,3,1.73);
    Rectangle rec1(0,3.46,3.46,2); //double ulcx, double ulcy, double length, double width

    ShapeMedia sh1(&rec1);
    ShapeMedia sh2(&tri1);
    ShapeMedia sh3(&tri2);


    combMedia comb1;
    comb1.add(&sh1);
    comb1.add(&sh2);
    comb1.add(&sh3);

    //std::cout << comb1.perimeter() <<std::endl;
    DOUBLES_EQUAL(25.83,comb1.perimeter(),epsilon);   //25.8329
}


TEST(eleven,AreaVisitor){

    Triangle tri1(-1,1.73,0,0,0,3.46);//double firX,double firY,double secX,double secY,double thirdX,double thirdY
    Triangle tri2(2,0,2,3.46,3,1.73);
    Rectangle rec1(0,3.46,3.46,2); //double ulcx, double ulcy, double length, double width

    ShapeMedia sh1(&rec1);
    ShapeMedia sh2(&tri1);
    ShapeMedia sh3(&tri2);


    combMedia comb1;
    combMedia comb2;


    comb1.add(&sh1);
    comb1.add(&sh2);
    comb1.add(&sh3);

    comb2.add(&comb1);



    /*
    AreaVisitor v1;
    sh2.accept(&v1);

    std::cout << v1.getArea() <<std::endl;
    DOUBLES_EQUAL(6.92,v1.getArea(),epsilon);
    */

    AreaVisitor v1;
    comb2.accept(&v1);

    //std::cout << v1.getArea() <<std::endl;
    DOUBLES_EQUAL(10.38,v1.getArea(),epsilon);   //10.38
}

TEST(eleven,PerimeterVisitor){

    Triangle tri1(-1,1.73,0,0,0,3.46);//double firX,double firY,double secX,double secY,double thirdX,double thirdY
    Triangle tri2(2,0,2,3.46,3,1.73);
    Rectangle rec1(0,3.46,3.46,2); //double ulcx, double ulcy, double length, double width

    ShapeMedia sh1(&rec1);
    ShapeMedia sh2(&tri1);
    ShapeMedia sh3(&tri2);


    combMedia comb1;
    combMedia comb2;

    comb1.add(&sh1);
    comb1.add(&sh2);
    comb1.add(&sh3);

    comb2.add(&comb1);


    PerimeterVisitor v1;
    comb2.accept(&v1);

    //std::cout << v1.Perimeter() <<std::endl;
    DOUBLES_EQUAL(25.84,v1.getPerimeter(),epsilon); //25.84
}


/*___________________HW4______________________________*/


TEST(twelve,shapeMediaBuilder){

    Circle c1(0,0,5);
    ShapeMediaBuilder sb;
    sb.buildShapeMedia(&c1);


    //std::cout <<sb.getMedia()->area()<<std::endl;
    DOUBLES_EQUAL(75,sb.getMedia()->area(),epsilon);

}


TEST(thirteen,dedcriptionVisitor){



    combMediaBuilder cb1;
    cb1.buildComboMedia();

    combMediaBuilder cb2;
    cb2.buildComboMedia();

    combMediaBuilder cb3;
    cb3.buildComboMedia();


    Rectangle r1(10,0,15,5);
    Circle c1(12,5,2);
    Rectangle r2(0,0,25,20);
    Triangle t1(0,20,16,32,25,20);

    cb1.buildShapeMedia(&r1);
    cb1.buildShapeMedia(&c1);


    cb2.buildAddComboMedia(cb1.getMedia());
    cb2.buildShapeMedia(&r2);

    cb3.buildAddComboMedia(cb2.getMedia());
    cb3.buildShapeMedia(&t1);



    AreaVisitor v1;
    cb3.getMedia()->accept(&v1);

    //std::cout << v1.getArea() <<std::endl;

    DescriptionVisitor dv;
    cb3.getMedia()->accept(&dv);

    //std::cout << dv.getDescription() <<std::endl;
    //std::cout << "combo(combo(combo(r(10 0 15 5) c(12 5 2) )r(0 0 25 20) )t(0 20 16 32 25 20) )" <<std::endl;

    //DOUBLES_EQUAL(737,v1.getArea(),epsilon);
    CHECK(std::string("combo(combo(combo(r(10 0 15 5) c(12 5 2) )r(0 0 25 20) )t(0 20 16 32 25 20) )") == dv.getDescription());
}

TEST(fourteen,text){


    Rectangle r2(0,0,25,20);
    Text t(&r2,"TEST");

    //std::cout << t.getInformation() <<std::endl;

    textMedia textm(&t);
    CHECK(std::string("TEST") == textm.getText()->getInformation());
}

TEST(fifteen,removes){  //for test__


    combMediaBuilder cb1;
    cb1.buildComboMedia();

    combMediaBuilder cb2;
    cb2.buildComboMedia();

    combMediaBuilder cb3;
    cb3.buildComboMedia();


    Rectangle r1(10,0,15,5);
    Circle c1(12,5,2);
    Rectangle r2(0,0,25,20);
    Triangle t1(0,20,16,32,25,20);

    cb1.buildShapeMedia(&r1);
    cb1.buildShapeMedia(&c1);


    cb2.buildAddComboMedia(cb1.getMedia());
    cb2.buildShapeMedia(&r2);

    cb3.buildAddComboMedia(cb2.getMedia());
    cb3.buildShapeMedia(&t1);


    //Circle c1(12,5,2);
    Circle test(12,5,5);
    ShapeMediaBuilder sb;
    sb.buildShapeMedia(&c1);
    cb3.getMedia()->removeMedia(sb.getMedia());
    //cb3.getMedia()->accept(&dv);

}


/*___________________HW5______________________________*/

TEST(sixteen,template1){

    //Mydocument my= new Mydocument();
    Document *dc = new Mydocument();

    try{
        //std::string s = my.openDocument("myShape.txt");
        //std::cout << s <<std::endl;

        CHECK(std::string("combo(r(0 0 3 2) c(0 0 5) combo(r(0 0 5 4) c(0 0 10) )combo(r(0 1 8 7) c(0 1 10) ))") == dc->openDocument("myShape.txt"));
    }catch(std::string name){
        std::cout << name <<std::endl;
    }
}

#include <stack>
TEST(seventeen,director)
{
    Mydocument my;
    std::string original = my.openDocument("myShape.txt");
    //std::cout << original <<std::endl;


    std::stack<MediaBuilder*> mb;
    MediaDirector md;
    md.setMediaBuilder(&mb);
    md.concrete(original);


    DescriptionVisitor dc;
    Media *a = mb.top()->getMedia();
    a->accept(&dc);
    //std::cout << "conclusion_________________________________________________________" <<std::endl;
    //std::cout << dc.getDescription() <<std::endl;

    CHECK(std::string("combo(r(0 0 3 2) c(0 0 5) combo(r(0 0 5 4) c(0 0 10) )combo(r(0 1 8 7) c(0 1 10) ))") == dc.getDescription());
}

TEST(eighteen,TAdirector)
{
    Mydocument my;
    std::string original = my.openDocument("myShape.txt");  //change your file's name


    std::stack<MediaBuilder*> mb;
    MediaDirector md;
    md.setMediaBuilder(&mb);
    md.concrete(original);


    DescriptionVisitor dc;
    Media *a = mb.top()->getMedia();
    a->accept(&dc);

    CHECK(std::string("combo(r(0 0 3 2) c(0 0 5) combo(r(0 0 5 4) c(0 0 10) )combo(r(0 1 8 7) c(0 1 10) ))") == dc.getDescription());   //change your test's string
}


#endif // UTSHAPES_H_INCLUDED
