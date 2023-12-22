#include<iostream>
using namespace std;

int main(){
    float x1,x2,x3,y1,y2,y3,slope1,slope2;
    cout<<"Enter (x1,y1):";
    cin>>x1>>y1;
    cout<<"Enter (x2,y2):";
    cin>>x2>>y2;
    cout<<"Enter (x3,y3):";
    cin>>x3>>y3;
    slope1=(y2-y1)/(x2-x1);
    slope2=(y3-y2)/(x3-x2);
    if(slope1==slope2){
        cout<<"in the same line";
    }else{
        cout<<"not in the same line";
    }
    return 0;
}