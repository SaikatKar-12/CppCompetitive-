#include<iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter two integers:";
    cin>>a>>b;
    if(a>b){
        cout<<a<<" is the greatest number";
    }else{
        cout<<b<<" is the greatest number";
    }
    return 0;
}