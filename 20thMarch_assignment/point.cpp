#include<iostream>
using namespace std;

int main(){
    int x,y;
    cout<<"enter point:";
    cin>>x>>y;
    if(x!=0 && y==0){
        cout<<"point lies in x axis";
    }else if(x==0 && y!=0){
         cout<<"point lies in y axis";
    }else if(x==0 && y==0){
         cout<<"point lies in origin";
    }else{
         cout<<"not applicable";
    }
    return 0;
}