#include<iostream>
using namespace std;

int main(){
    int n,a=1,b=1,temp;
    cout<<"Enter number:";
    cin>>n;
    cout<<a;
    for(int i=0;i<n-1;i++){
        cout<<" "<<b; 
        temp=a+b;
        a=b;
        b=temp;
       
    }
    return 0;
}