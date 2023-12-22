#include<iostream>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b && b==c && c==a){
        cout<<"equilateral";
    }else if(a!=b && b!=c && c!=a){
        cout<<"scalene";
    }else{
        cout<<"isosceles";
    }
    return 0;
}