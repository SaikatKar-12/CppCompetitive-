#include<iostream>
using namespace std;

int main(){
     int n,nst=1,nsp;
    cout<<"Enter number:";
    cin>>n;
    nsp=1;
    for(int i=1;i<=n;i++){
        cout<<" ";
    }
    cout<<"1"<<endl;
    for(int i=1;i<=n;i++){
       
         for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
         cout<<i+1;
         for(int k=1;k<=nsp;k++){
            cout<<" ";
        }
        cout<<i+1;
        nsp+=2;
        
        cout<<endl;
    }
    return 0;
}