#include<iostream>
using namespace std;
int reverse(int n,int rev){
    if(n==0) return rev;
    reverse(n/10,rev*10+n%10);
}
int main(){
    cout<<reverse(123080,0);
    return 0;
}