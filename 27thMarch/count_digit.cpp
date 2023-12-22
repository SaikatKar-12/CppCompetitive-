#include<iostream>
using namespace std;

int main(){
    int n,rev=0;
    cout<<"Enter integer:";
    cin>>n;
    
    while(n>0){
        rev=rev*10+n%10;
        n/=10;
    }
    cout<<"reverse of digits "<<rev;
    return 0;
}