#include<iostream>
using namespace std;

int main(){
    int x=45;
    int lo=0;
    int hi=x;
    bool flag=false;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(mid*mid==x){
            flag=true;
            cout<<"yes "<<mid;
            break;
        }else if(mid*mid>x) hi=mid-1;
        else lo=mid+1;
    }
    if(flag==false) cout<<"no";
    return 0;
}