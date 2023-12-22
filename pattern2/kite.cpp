#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    for(int j=1;j<=n;j++){
        cout<<" ";
       }
    cout<<"*"<<endl;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n-i;j++){
        cout<<" ";
       }
       cout<<"*";
       for(int j=1;j<=i-1;j++){
        cout<<" ";
       }
        cout<<"*";
       for(int j=1;j<=i-1;j++){
        cout<<" ";
       }
       cout<<"*";
       cout<<endl;
    }
    for(int i=1;i<=2*n+1;i++){
        cout<<"*";
    }
    cout<<endl;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=i;j++){
        cout<<" ";
       }
       cout<<"*";
       for(int j=1;j<=n-i-1;j++){
        cout<<" ";
       }
        cout<<"*";
       for(int j=1;j<=n-i-1;j++){
        cout<<" ";
       }
       cout<<"*";
       cout<<endl;
    }
    for(int j=1;j<=n;j++){
        cout<<" ";
       }
    cout<<"*"<<endl;
    return 0;
}