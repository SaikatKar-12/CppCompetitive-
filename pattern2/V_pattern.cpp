#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    int nsp=n+2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==n) continue;
            else if(i==j) cout<<"*";
            else cout<<" ";
        }
        for(int j=1;j<=nsp;j++){
            cout<<" ";
           
        }
         nsp-=2;
        
         cout<<"*";
        cout<<endl;
    }
    return 0;
}