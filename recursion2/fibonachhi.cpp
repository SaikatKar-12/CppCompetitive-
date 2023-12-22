#include<iostream>
using namespace std;
int fibo(int n){
    if(n==1 || n==2) return 1;
    else return fibo(n-1)+fibo(n-2);
}
int main(){
    //1 1 2 3 5 8 13
    cout<<fibo(7);
    return 0;
}