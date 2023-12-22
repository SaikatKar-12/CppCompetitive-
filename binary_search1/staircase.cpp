#include<iostream>
using namespace std;

int main(){
    int n=5;
    int count=1;
    int row=1;
    while(n>0){
        n-=count;
        if(n>0) count++;
        else cout<<count-1;
    }
    return 0;
}