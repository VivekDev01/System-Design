#include<bits/stdc++.h>

using namespace std;

class TwoDShape{
public:
    virtual double getArea() = 0;
    ~TwoDShape(){};
};

class ThreeDShape{
public:
    virtual double getArea() = 0;
    virtual double getVolume() = 0;
    ~ThreeDShape(){};
};

class Rectangle : public TwoDShape{
    double height=0;
    double width=0;
public:
    Rectangle(double height, double width){
        this->height= height;
        this->width = width;
    }
    double getArea(){
        cout<<"Area of square: "<<height * width<<endl;
        return height * width;
    }
};


class Cube : public ThreeDShape{
    double side = 0;
public:
    Cube(double side){
        this->side= side;
    }
    double getArea(){
        cout<<"Area of cube: "<<side*side*6<<endl;
        return side* side *6;
    }
    double getVolume(){
        cout<<"Volume of Cube: "<<side * side * side<<endl;
        return side * side * side;
    }
};

int main(){
    Rectangle * rec = new Rectangle(4.2, 5.3);
    rec->getArea();
    // rec->getVolume();

    cout<<"----------X------------X-----------"<<endl;

    Cube * cube = new Cube(4.2);
    cube->getArea();
    cube->getVolume();
}


// by creating 2 separate interfaces ISP is followed.