#include<iostream>
using namespace std;
#define pi 3.14
int main(){
    float rad,area,peri;
    cout<<"Enter radius:";
    cin>>rad;
    area=pi*rad*rad;
    peri=2*pi*rad;
    if(area>peri){
        cout<<"area>peri";
    }else{
        cout<<"area<peri";
    }
    return 0;
}