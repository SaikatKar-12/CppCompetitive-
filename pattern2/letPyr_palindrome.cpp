#include<iostream>
using namespace std;

int main(){
     int n,nst=1,nsp;
    cout<<"Enter number:";
    cin>>n;
    nsp=n-1;
    
    for(int i=1;i<=n;i++){
        int a=64+i;
         for(int j=1;j<=nsp;j++){
            cout<<" ";
        }
        nsp--;
        for(int k=1;k<=i;k++){
            cout<<(char)a;
            a--;
        }
        for(int j=1;j<=i-1;j++){
            cout<<(char)(j+65);
        }
        nst+=2;
        cout<<endl;
    }
    return 0;
}