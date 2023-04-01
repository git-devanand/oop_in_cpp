#include<iostream>
using namespace std;

int add(int a, int b){
    return a+b;
}

int add (int a, int b, int c){
    return a+b+c;
}

int main() {
    cout<<add(5,3)<<"\n";
    cout<<add(4,5,6)<<"\n";

    return 0;
}
