#include<iostream>
using namespace std;
float circle_area(int r){
    float area;
    area=r*r*3.14;
    return area;
}
int main(){
    int r;
    cout<<"Enter r:";
    cin>>r;
    cout<<circle_area(r);
    return 0;
}