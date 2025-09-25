#include<bits/stdc++.h>
using namespace std;

class TalkableRobot{ //Strategy Interface for talk
public: 
    virtual void talk() = 0;
    virtual~ TalkableRobot(){};
};
class NormalTalk : public TalkableRobot{
public:
    void talk() override{
        cout<<"hey i am talking normally"<<endl;
    }
};
class NoTalk : public TalkableRobot{
public:
    void talk() override{
        cout<<"hey i am not talking"<<endl;
    }
};

class WalkableRobot{//Strategy Interface for walk
public: 
    virtual void walk() = 0;
    virtual ~ WalkableRobot(){};
};
class NormalWalk : public WalkableRobot{ // concrete class to walk normally
public:
    void walk() override{
        cout<<"hey i am walking normally"<<endl;
    }
};
class NoWalk : public WalkableRobot{ // concrete class to not walk
public:
    void walk() override{
        cout<<"hey i am not walking"<<endl;
    }
};


class FlyableRobot{//Strategy Interface for fly
public: 
    virtual void fly() = 0;
    virtual ~ FlyableRobot(){};
};
class NormalFly : public FlyableRobot{
public:
    void fly() override{
        cout<<"hey i am flying normally"<<endl;
    }
};
class NoFly : public FlyableRobot{
public:
    void fly() override{
        cout<<"hey i am not flying"<<endl;
    }
};


class Robot{  // abstract class for robots
protected:
    WalkableRobot * w;
    TalkableRobot * t;
    FlyableRobot * f;
public:
    void walk(){
        w->walk();
    }
    void talk(){
        t->talk();
    }
    void fly(){
        f->fly();
    }
    virtual void projection() = 0;
    virtual ~ Robot(){};
};

class CompanionRobot : public Robot{ // concrete class companion
public:
    CompanionRobot(WalkableRobot * w, TalkableRobot * t, FlyableRobot * f){
        this->w = w;
        this->t = t;
        this->f = f;
    }
    void projection() override{
        cout<<"projecting the robo"<<endl;
    }
};


int main(){
    CompanionRobot * companion = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    companion->projection();
    companion->walk();
    companion->fly();
}