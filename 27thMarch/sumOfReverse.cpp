#include<iostream>
using namespace std;

int main(){
    int n,rev=0,rem,num;
    cout<<"Enter number:";
    cin>>n;
    num=n;
    while(n>0){
        rem=n%10;
        rev=rev*10+rem;
        n/=10;
    }
    cout<<num+rev;
    return 0;
}