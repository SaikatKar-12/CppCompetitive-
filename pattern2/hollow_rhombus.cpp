#include<iostream>
using namespace std;

int main(){
     int n,nst=1,nsp;
    cout<<"Enter number:";
    cin>>n;
    nsp=n-1;
    for(int i=1;i<=n;i++){
        cout<<" ";
    }
    cout<<"*"<<endl;
    for(int i=1;i<=2*n-1;i++){
         for(int j=1;j<=nsp;j++){
            cout<<" ";
        }
        if(i<n){
            nsp--;
        }else{
            nsp++;
        }
        cout<<"*";
        for(int j=1;j<=nst;j++){
            cout<<" ";
        }
        if(i<n){
           nst+=2; 
        }else{
            nst-=2;
        }
         cout<<"*";
        cout<<endl;
    }
     for(int i=1;i<=n;i++){
        cout<<" ";
    }
    cout<<"*"<<endl;
    return 0;
}