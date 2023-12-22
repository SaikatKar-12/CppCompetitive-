#include<iostream>
using namespace std;

int main(){
    int n,k;
    cout<<"Enter number:";
    cin>>n;
    for(int i=1;i<=n;i++){
        
        for( k=i;k>0;k--){
            cout<<k;
        }
        cout<<endl;
    }
    return 0;
}