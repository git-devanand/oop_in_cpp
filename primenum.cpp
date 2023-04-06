#include<bits/stdc++.h>

using namespace std;

int main(){
int x;
cin>>x;

int start = 2;

while(start < x){
    if(x%start == 0){
        cout<<"Not Prime"<<"\n";
        return 0;
    }
    start++;
}

cout<<"Prime"<<"\n";

return 0;

}