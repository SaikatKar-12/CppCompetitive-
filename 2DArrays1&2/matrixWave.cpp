#include<iostream>
using namespace std;

int main(){
    int m,n;
    cout<<"enter 1st array row and size:";
    cin>>m>>n;
    cout<<"Enter  array elements:";
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           cin>>a[i][j];
        }
    }
    cout<<endl;
    for(int i=0;i<m;i++){
        if(i%2==0){
            for(int j=0;j<m;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }else{
            for(int j=m-1;j>=0;j--){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
   
    return 0;
}
