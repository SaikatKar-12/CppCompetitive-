#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(a==0) return b;
    gcd(b%a,a);
}
int main(){
    int a=27;
    int b=45;
    cout<<gcd(b,a);
    return 0;
}