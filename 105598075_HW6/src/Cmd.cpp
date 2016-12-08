#include "Cmd.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include <map>
#include <typeinfo>
#include <cxxabi.h>
#include <fstream>
#include "MediaDirector.h"
#include "combMediaBuilder.h"
#include "ShapeMediaBuilder.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"
#include "DescriptionVisitor.h"
#include "DescriptionNameVisitor.h"
#include "Circle.h"
#include <chrono>
#include <thread>
#include <queue>
#include <setValueVisitor.h>

typedef std::pair<std::string, Media*> MyPair;
template <typename T> char* get_typename(T& object)
{
    return abi::__cxa_demangle(typeid(object).name(), 0, 0, 0);
}

Cmd::Cmd(){}

Cmd::~Cmd(){}

bool checkFileName(std::string fileName){
    std::vector<std::string> temp;
    std::string temper;
    int top=0;
    int last=fileName.size();
    temper = fileName;
    //temper = fileName.substr(1,last-2);

    //std::cout << temper << std::endl;
    int found=temper.find(".");
    while(found!=-1){
        temp.push_back(temper.substr(top,found));
        temper = temper.substr(found+1,last-found);
        found=temper.find(".");
    }
    temp.push_back(temper);


    if(temp.size()==2){
        //std::cout << "correct fileName" << std::endl;
        //std::cout << "i(0) "<< temp.at(0) << std::endl;
        //std::cout << "i(1) "<< temp.at(1) << std::endl;
        if(temp.at(1).compare("txt")==0){
            return 1;
        }
        else{
            std::cout << "it only support .txt " << std::endl;
        }
    }
    else{
        /*for(int i=0;i<temp.size();i++)
            std::cout << temp.at(i) << std::endl;*/

        std::cout << "error structure" << std::endl;
        return 0;
    }
}


void add(std::string addName,std::string combName,std::map<std::string,Media*> *names){

    std::map<std::string,Media*>::iterator addN;
    std::map<std::string,Media*>::iterator comb;
    std::string classN;
    DescriptionVisitor dVisitor;
    DescriptionNameVisitor dnVisitor;

    if(names->find(addName)!=names->end()){
        addN = names->find(addName);
        //std::cout << "found, " << addName<< std::endl;
        if(names->find(combName)!=names->end()){    //check exit,and check next
            comb = names->find(combName);
            classN = get_typename(*(comb->second));
            if(classN.compare("combMedia")==0){ //check combMedia
                //std::cout << "prepare to add" << std::endl;
                Media *a = addN->second;
                comb->second->add(a);
                comb->second->accept(&dVisitor);
                comb->second->accept(&dnVisitor);

                std::cout << ">> " << combName << " = " << dnVisitor.getDescription() << "= " << dVisitor.getDescription()<<std::endl;
            }
            else{
                std::cout << combName << "is not a combMedia" << std::endl;
            }
        }
        else{
            std::cout << "Not found "<<combName << std::endl;
        }
    }
    else{
        std::cout << "Not found "<<addName << std::endl;
    }

}
void save (std::string funName,std::string fileName,std::map<std::string,Media*> *names){   //fileName doesn't check

    std::map<std::string,Media*>::iterator it;
    std::string classN;
    std::fstream fs;
    int last=0;
    DescriptionVisitor dVisitor;
    DescriptionNameVisitor dnVisitor;

    /*std::cout << fileName << std::endl;
    int last = fileName.size();
    fileName = fileName.substr(1,last-2);
    std::cout << fileName << std::endl;*/

    if(names->find(funName) == names->end()){
        std::cout << "not found" << std::endl;
    }
    else{
        it = names->find(funName);
        //std::cout << "found" << std::endl;
        classN = get_typename(*(it->second));
        //std::cout << classN <<std::endl;
        if(classN.compare("ShapeMedia")==0){
            //std::cout << "save ShapeMedia" <<std::endl;
            //it->second->accept(&aVisitor);
            //std::cout << ">> " <<aVisitor.getArea()<<std::endl;
        }
        else if (classN.compare("combMedia")==0){
            //std::cout << "prepare datas" <<std::endl;
            //it->second->accept(&aVisitor);
            //std::cout << ">> " <<aVisitor.getArea()<<std::endl;
            last = fileName.size();
            fileName = fileName.substr(1,last-2);   //delete ""
            if(checkFileName(fileName)){
                //std::cout << "correct" << std::endl;
                fs.open(fileName, std::ios::out);

                it->second->accept(&dVisitor);
                //std::cout << dVisitor.getDescription() << std::endl;

                it->second->accept(&dnVisitor);
                //std::cout << dnVisitor.getDescription() << std::endl;

                if(fs.is_open()){
                    fs << dVisitor.getDescription() <<std::endl;
                    fs << dnVisitor.getDescription() <<std::endl;
                    fs.close();
                    std::cout <<std::endl<<">> " <<funName<<" saved to " << fileName <<std::endl;
                }
                else{
                    std::cout << "should not be here" << std::endl;
                }
            }
            else{
                std::cout << "error fileName" << fileName << std::endl;
            }
        }
        else{
            std::cout << "wrong type" << std::endl;
        }
    }
}

void calculate(std::string funName,std::string method,std::map<std::string,Media*> *names){ //areaPerimeter.at(0),areaPerimeter.at(1),&names

    std::map<std::string,Media*>::iterator it;
    //std::cout << funName << std::endl;
    //std::cout << method << std::endl;
    std::string classN;
    AreaVisitor aVisitor;
    PerimeterVisitor pVisitor;

    if(names->find(funName)==names->end()){   //not found
        std::cout << "not found" <<std::endl;
    }
    else{//found
        //std::cout << "found" <<std::endl;
        it = names->find(funName);
        //std::cout << it->second->getName() << std::endl;

        if(method.compare("area?")==0){
            classN = get_typename(*(it->second));
            //std::cout << classN <<std::endl;
            if(classN.compare("ShapeMedia")==0){
                //std::cout << "calculate ShapeMedia area" <<std::endl;
                it->second->accept(&aVisitor);
                std::cout << ">> " <<aVisitor.getArea()<<std::endl;
            }
            else if (classN.compare("combMedia")==0){
                //std::cout << "calculate combMedia area" <<std::endl;
                it->second->accept(&aVisitor);
                std::cout << ">> " <<aVisitor.getArea()<<std::endl;
            }
            else{
                std::cout << "wrong type" << std::endl;
            }
        }
        else if(method.compare("perimeter?")==0){

            classN = get_typename(*(it->second));
            //std::cout << classN <<std::endl;
            if(classN.compare("ShapeMedia")==0){
                //std::cout << "calculate ShapeMedia perimeter" <<std::endl;
                it->second->accept(&pVisitor);
                std::cout << ">> " <<pVisitor.getPerimeter()<<std::endl;
            }
            else if (classN.compare("combMedia")==0){
                //std::cout << "calculate combMedia perimeter" <<std::endl;
                it->second->accept(&pVisitor);
                std::cout << ">> " <<pVisitor.getPerimeter()<<std::endl;
            }
            else{
                std::cout << "wrong type" << std::endl;
            }
        }
        else{
            std::cout << "error method -> "<< method <<"  ,should be area? or perimeter? "<<std::endl;
        }
    }

}
void split(std::string cmd ,std::vector<std::string> *s){   //- def a = Circle(2,1,1)

    std::string temp="";
    char tab2[1024];
    //std::cout << cmd <<std::endl;
    std::strcpy(tab2, cmd.c_str());
    //std::cout << strlen(tab2) <<std::endl;
    for(int i=0; i<strlen(tab2); i++){
        if(tab2[i]==' '){//split command
            //std::cout << temp <<std::endl;
            s->push_back(temp);
            temp.clear();
        }
        else{
            temp+=tab2[i];
            if(i==strlen(tab2)-1){
                s->push_back(temp);
                temp.clear();
            }
        }
    }
}
void splitBrackets(std::string func,std::queue<std::string> *name,std::queue<std::string> *checkSorC){

    //std::cout << func << std::endl;
    char tab2[1024];
    std::string temp="";
    std::strcpy(tab2, func.c_str());

    for(int i=0;i<strlen(tab2);i++){    //split command

        if(tab2[i]=='{' || tab2[i]==' ' || tab2[i]=='}'){   //tab2[i]=='{' || tab2[i]==' ' || tab2[i]=='}'

            if(tab2[i]==' '){
                //std::cout << "shape's -> " <<temp<< std::endl;
                checkSorC->push("shape");
                name->push(temp);
                temp.clear();
            }
            else{
                //std::cout << temp << std::endl;         //load "myShapes.txt"
                checkSorC->push("combo");
                name->push(temp);
                temp.clear();
            }
        }
        else
            temp+=tab2[i];

        /*if(tab2[i]==' ' && tab2[i-1]==')')
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
        }*/


    }

}
void splitPoint(std::string number,std::vector<std::string> *s){    //a.area()?  b.perimeter()?
    std::string temp = number;
    std::string temper;
    int last = temp.size();
    int first =0;
    int found ;// temp.find_first_of(")") -- > not found is -1

    //std::cout << "number is " << temp<<std::endl;
    //std::cout << "size is " << last <<std::endl;
    //std::cout << "first appear is "<< temp.find_first_of(",") <<std::endl;

    if(temp.find_first_of(".")!=-1){
        while(temp.find_first_of(".")!=-1){
            //std::cout << "=============" <<std::endl;
            found = temp.find_first_of(".");
            temper = temp.substr(first,found-first);
            s->push_back(temper);
            //std::cout << "number is " << temper <<std::endl;

            temp = temp.substr(found+1,last-found);
            //std::cout << "last number is " << temp<<std::endl;
        }
        s->push_back(temp); //final number need to push
    }
    else{
        std::cout << "should not be here" <<std::endl;
    }
}
void splitDot(std::string number,std::vector<std::string> *s){  //2,1,1
    std::string temp = number;
    std::string temper;
    int last = temp.size();
    int first =0;
    int found ;// temp.find_first_of(")") -- > not found is -1

    //std::cout << "number is " << temp<<std::endl;
    //std::cout << "size is " << last <<std::endl;
    //std::cout << "first appear is "<< temp.find_first_of(",") <<std::endl;

    if(temp.find_first_of(",")!=-1){
        while(temp.find_first_of(",")!=-1){
            //std::cout << "=============" <<std::endl;
            found = temp.find_first_of(",");
            temper = temp.substr(first,found-first);
            s->push_back(temper);
            //std::cout << "number is " << temper <<std::endl;

            temp = temp.substr(found+1,last-found);
            //std::cout << "last number is " << temp<<std::endl;
        }
        s->push_back(temp); //final number need to push
    }
    else{   //only on value
        s->push_back(temp);
    }
}

void load(std::string fileName,std::map<std::string,Media*> *names){

    std::ifstream ifs;
    std::string temp=" ";
    std::string topName;
    std::vector<std::string> funS;
    std::queue<std::string> funNames;
    std::queue<std::string> checkSorC;
    std::stack<MediaBuilder*> create;
    int last;
    MediaDirector md;

    //std::string value;
    //std::string nameTemp;

    last = fileName.size();

    if(fileName.at(0)=='"' && fileName.at(last-1)=='"'){
        //std::cout << "correct " <<std::endl;
        fileName = fileName.substr(1,last-2);

        if(checkFileName(fileName)){
            //std::cout << "Prepare to load "<<std::endl;

            ifs.open(fileName,std::ifstream::in);
            getline(ifs,temp);
            funS.push_back(temp);
            //std::cout << temp << std::endl;
            while(!ifs.eof()){
                getline(ifs,temp);
                //std::cout << temp << std::endl;
                funS.push_back(temp);
                //std::this_thread::sleep_for(std::chrono::nanoseconds(1000));
            }

            //std::cout << funS.size() <<std::endl;
            //for(int i=0;i<funS.size();i++)
                //std::cout << funS.at(i) <<std::endl;

            if(funS.size()==3 && funS.at(2).compare("")==0){  //comboExclamation{cSmall cMale }= combo(c(2 1 1)  c(3 2 1) )
                splitBrackets(funS.at(1),&funNames,&checkSorC);

                /*for(int i=0;i<=funNames.size();i++){
                    std::cout << funNames.front() << " is a "<<checkSorC.front()<< std::endl;
                    checkSorC.pop();
                    funNames.pop();
                }*/

                /*************create Combo*************/
                topName = funNames.front();
                std::cout << "Name is ->>>>>>>>>>>>>>>>>> " << topName << std::endl;
                md.setMediaBuilder(&create);
                md.concrete(funS.at(0));    //0-> combo(c(2 1 1) c(3 2 1) )    1-> comboExclamation{cSmall cMale }=


                DescriptionVisitor dc;
                Media *a = create.top()->getMedia();
                a->accept(&dc);
                std::cout << dc.getDescription() << std::endl;

                setValueVisitor sV(&funNames);
                a->accept(&sV);

                names->insert(MyPair(topName,a));
                /**************************************/

                /*************create shapeS*************/

                //  checkSorC need to split combo(c(2 1 1) c(3 2 1) ) ·Ó¶¶§Ç

            }
            else if(funS.size()==3 && funS.at(1).compare("")==0){  //save shapeMedia

            }
            else{
                std::cout << "error input parameter structure in file" << std::endl;
            }
        }
        else{
            std::cout << "file name structure is wrong,-> " << fileName <<std::endl;
        }
    }
    else{
        std::cout << fileName << "  prefer to add \" like follows, "<< " \""<<fileName<<"\" "<<std::endl;
    }
}


void def(std::string name,std::string formula,std::map<std::string,Media*> *names){

    MediaDirector dc;
    ShapeMediaBuilder shB;
    combMediaBuilder comB;
    std::vector<std::string> numbers;
    std::vector<std::string> shpNames;
    std::vector<Media*> combMaterial;
    std::string temp=formula;
    std::string typeN;
    std::string number;
    std::map<std::string,Media*>::iterator it;
    bool yesToC=0;

    //std::cout << name <<"___" <<formula <<std::endl;
    int shLocation = temp.find("(");    //doesn't find is -1
    int shLast = temp.length() - shLocation - 2;

    int cLocation = temp.find("{");     //doesn't find is -1
    int cLast = temp.length() - cLocation - 2;

    if(shLocation!=-1){ // shape()
        //std::cout << "(((----------------------------------------------" <<std::endl;
        //std::cout << "shLocation is " << shLocation <<std::endl;
        //std::cout << "shLast is " << shLast <<std::endl;

        typeN = temp.substr(0,shLocation);
        //std::cout << " typeN is "<<typeN << std::endl;
        number = temp.substr(shLocation+1,shLast);
        //std::cout << " number is "<<number << std::endl;

        if(typeN.compare("Circle")==0){ //(std::string content,std::vector<double> *n,MediaBuilder *s)
            //std::cout << "Circle" <<std::endl;
            //std::cout << "number is " << number<<std::endl;
            splitDot(number,&numbers);
            /*if(numbers.size()!=0) //show number
            {
                for(int i=0; i<numbers.size(); i++)
                    std::cout << numbers.at(i) <<std::endl;
            }*/

            if(numbers.size()==3){
                //std::cout << "correct parameter structure in " << name << "->"<<typeN<<std::endl;
                dc.buildShpae(typeN,&numbers,&shB);
                Media *s = shB.getMedia();
                s->setName(name);
                names->insert(MyPair(name,s));
                //std::cout << "create successuflly " << name << "->"<<typeN<<std::endl;
                //it = names->find(name);
                std::cout << ">> "  << formula <<std::endl;

            }else{
                std::cout << "error parameter structure in  " << name << "->"<< typeN<<std::endl;
            }
        }
        else if(typeN.compare("Rectangle")==0){
            //std::cout << "Rectangle" <<std::endl;
            //std::cout << "number is " << number<<std::endl;
            splitDot(number,&numbers);

            if(numbers.size()==4){
                //std::cout << "correct parameter structure in " << name << "->"<< typeN<<std::endl;
                dc.buildShpae(typeN,&numbers,&shB);
                Media *s = shB.getMedia();
                s->setName(name);
                names->insert(MyPair(name,s));
                std::cout << ">> "  << formula <<std::endl;
                //std::cout << "create successuflly " << name << "->"<<typeN<<std::endl;

            }else{
                std::cout << "error parameter structure in  " << name << "->"<< typeN<<std::endl;
            }
        }
        else if(typeN.compare("Triangle")==0){
            //std::cout << "Triangle" <<std::endl;
            //std::cout << "number is " << number<<std::endl;
            splitDot(number,&numbers);

            if(numbers.size()==6){
                //std::cout << "correct parameter structure in " << name << "->"<< typeN<<std::endl;
                try{
                    dc.buildShpae(typeN,&numbers,&shB);
                    Media *s = shB.getMedia();
                    s->setName(name);
                    names->insert(MyPair(name,s));
                    std::cout << ">> "  << formula <<std::endl;
                    //std::cout << "create successuflly " << name << "->"<<typeN<<std::endl;
                }catch(std::string s){
                    std::cout << s<< std::endl;
                }
            }else{
                std::cout << "error parameter " << name << "->"<< typeN<<std::endl;
            }
        }
        else{
            std::cout << "error function " << name << "->" << typeN<<std::endl;
        }


    }
    else if(cLocation!=-1){ //combo{}   (std::string content,std::vector<Media*> *n,MediaBuilder *s)
        //std::cout << "{{{----------------------------------------------" <<std::endl;
        //std::cout << "cLocation is " << cLocation <<std::endl;
        //std::cout << "cLast is " << cLast <<std::endl;

        typeN = temp.substr(0,cLocation);
        //std::cout << " typeN is "<<typeN << std::endl;
        number = temp.substr(cLocation+1,cLast);
        //std::cout << " number is "<<number << std::endl;

        if(typeN.compare("combo")==0){
            //std::cout << "combo" <<std::endl;
            splitDot(number,&shpNames);
            //std::cout << "composition names \""<< name << "\" -> " << typeN <<"  are follows "<<std::endl;
            /*if(shpNames.size()!=0){ //show
                for(int i=0; i<shpNames.size(); i++)
                    std::cout << shpNames.at(i) <<std::endl;
            }*/

            if(shpNames.size()!=0){
                for(int i=0; i<shpNames.size(); i++){
                    //std::cout << shpNames.at(i) <<std::endl;
                    if(names->find(shpNames.at(i))==names->end()){  //not found
                        std::cout << shpNames.at(i) <<" doesn't exist "<<std::endl;
                        yesToC=0;
                    }
                    else{   //found
                        //std::cout << shpNames.at(i) <<" exist "<<std::endl;
                        yesToC=1;
                    }
                }
            }   //end if


            if(yesToC){
                //std::cout << "----------------------------------------------------------"<<std::endl;
                //std::cout << " prepare to create combo "<<std::endl;
                //MediaDirector::buildComb(std::string content,std::vector<Media*> *n,MediaBuilder *s)
                for(int i=0; i<shpNames.size(); i++){
                    it = names->find(shpNames.at(i));
                    //std::cout <<  it->second->getName() <<std::endl;
                    combMaterial.push_back(it->second);
                }
                /*for(int i=0;i<combMaterial.size();i++)
                    std::cout << combMaterial.at(i)->getName() << std::endl;*/
                    dc.buildComb(&combMaterial,&comB);

                    Media *s = comB.getMedia();
                    s->setName(name);
                    names->insert(MyPair(name,s));
                    //std::cout << "create successuflly " << name << "->"<<typeN<<std::endl;

            }else{
                std::cout << "----------------------------------------------------------"<<std::endl;
                std::cout << " upper names don't exit,so it can't build combo "<<std::endl;
            }
        }
        else{
            std::cout << "error function " << typeN <<std::endl;
        }
    }
    else{
        std::cout << "error syntax in def {}()" <<std::endl;
    }
}


void Cmd::run(){

    std::vector<std::string> cmds;
    std::vector<std::string> areaPerimeter;
    std::map<std::string,Media*>::iterator it;
    //std::map<std::string,Media*> names;
    std::string cmd;

    /*ShapeMedia *t = new ShapeMedia(new Circle(2,1,1));
    t->setName("test1234");
    names.insert(MyPair("test",t)); //upper for test in def-*/

    while(cmd!="exit"){
        std::cout << "enter cmd " <<std::endl<<":-";
        std::getline(std::cin,cmd);
        //std::cout << "enter cmd is " <<cmd  <<std::endl;'s

        split(cmd,&cmds);
        if(!cmds.empty()){  //check cmds.at(0)=="-" else continue
            if(cmds.size()>=1 || cmds.size()<=5){
                //std::cout << "correct syntax" <<std::endl;
            }
            else{   //error syntax
                std::cout << "error syntax first" <<std::endl;
                cmds.clear();
                continue;
            }
            /*if(cmds.at(0).compare("-")!=0 && cmds.size()<2 && cmds.size()>5){
                std::cout << "error syntax" <<std::endl;
                cmds.clear();
                continue;
            }*/
            if(cmds.at(0).compare("def")==0){
                if(cmds.at(2).compare("=")==0 && cmds.size()==4){
                    //std::cout << "Action is def" <<std::endl;
                    //std::cout << "==============" <<std::endl;
                    def(cmds.at(1),cmds.at(3),&names);
                }
                else{  //error syntax

                    std::cout << "error syntax at def structure" <<std::endl;
                    //cmds.clear();
                    //continue;
                }
            }
            else if(cmds.at(0).compare("add")==0){
                    if(cmds.size()==4 && cmds.at(2).compare("to")==0){
                        //std::cout << "Action is add" <<std::endl;
                        //std::cout << "==============" <<std::endl;
                        add(cmds.at(1),cmds.at(3),&names);
                    }
                    else{
                        std::cout << "error syntax at def structure" <<std::endl;
                    }
            }
            else if(cmds.at(0).compare("delete")==0){
                std::cout << "Action is delete" <<std::endl;
                std::cout << "================" <<std::endl;
            }
            else if(cmds.at(0).compare("show")==0){
                //std::cout << "Action is show" <<std::endl;
                //std::cout << "==============" <<std::endl;
                for (std::map<std::string,Media*>::iterator it=names.begin(); it!=names.end(); ++it)  //show run()'s names
                    std::cout << it->second->getName() << std::endl;
            }
            else if(cmds.at(0).compare("save")==0){
                if(cmds.size()==4 && cmds.at(2).compare("to")==0){
                    //std::cout << "Action is save" <<std::endl;
                    //std::cout << "==============" <<std::endl;
                    save(cmds.at(1),cmds.at(3),&names);
                }
                else{
                    std::cout << "save ,, but wrong structure " <<std::endl;
                }
            }
            else if(cmds.at(0).compare("load")==0){
                std::cout << "Action is load" <<std::endl;
                std::cout << "==============" <<std::endl;
                if(cmds.size()==2){
                    load(cmds.at(1),&names);
                }
                else{
                    std::cout << "load ,, but wrong structure "<< std::endl;
                }
            }
            else{   //area() perimeter()    cmds.at(0)
                splitPoint(cmds.at(0),&areaPerimeter);
                /*for(int i=0;i<areaPerimeter.size();i++){    //show
                    std::cout << "i(" << i <<")"<<areaPerimeter.at(i) << std::endl;
                }*/
                if(areaPerimeter.size()<=2){

                    if(names.find(areaPerimeter.at(0))==names.end()){  //not found obj's name
                        std::cout << areaPerimeter.at(0) <<" doesn't exist "<<std::endl;
                    }
                    else{   //found
                        //std::cout << "prepare to calculate " << areaPerimeter.at(1) << std::endl;
                        calculate(areaPerimeter.at(0),areaPerimeter.at(1),&names);
                    }
                }else{
                    std::cout << "error cmd structure - >" << cmds.at(0) << "   ,should be A.area? or A.perimeter?" << std::endl;
                }

            }
        }
        std::cout << "----------------------------------------------" <<std::endl;
        cmds.clear();
        areaPerimeter.clear();
    }//end while

}


