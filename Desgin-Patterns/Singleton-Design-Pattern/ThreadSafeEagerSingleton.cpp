#include<bits/stdc++.h>
using namespace std;

class Singleton{
    static Singleton * s;
    Singleton(){
        cout<<"new object created"<<endl;
    }
public:
    static Singleton* getInstance(){ 
        return s;
    }
};

Singleton* Singleton::s= new Singleton(); // HERE STATIC VARIABLE IS DEFINED AT TIME OF DECLARATION. 
//ONLY DRAWBACK OF THIS IS MEMORY WASTAGE IF OBJECT IS NOT BEING USED

int main(){
    Singleton * s1 = Singleton::getInstance(); 
    Singleton * s2 = Singleton::getInstance();

    cout<< (s1==s2) <<endl;
}