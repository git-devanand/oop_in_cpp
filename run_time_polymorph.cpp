#include<iostream>
using namespace std;

class A{
public:
    virtual void fun() {
        cout<<"base"<<"\n";
    }
};

class B:public A {
public:
    void fun() {
        cout<<"derived "<<"\n";
    }
};


int main()
{
    A *a = new B;
    a->fun();

    return 0;
}
