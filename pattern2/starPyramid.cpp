#include<iostream>
using namespace std;

int main(){
     int n,nst=1,nsp;
    cout<<"Enter number:";
    cin>>n;
    nsp=n-1;
    for(int i=1;i<=n;i++){
         for(int j=1;j<=nsp;j++){
            cout<<" ";
        }
        nsp--;
        for(int j=1;j<=nst;j++){
            cout<<"*";
        }
        nst+=2;
        cout<<endl;
    }
    return 0;
}