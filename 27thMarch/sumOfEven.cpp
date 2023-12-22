#include<iostream>
using namespace std;

int main(){
    int n,sum=0,rem;
    cout<<"Enter number:";
    cin>>n;
    while(n>0){
        rem=n%10;
        if(rem%2==0){
            sum=sum+rem;
        }
        n/=10;
    }
    cout<<sum;
    return 0;
}