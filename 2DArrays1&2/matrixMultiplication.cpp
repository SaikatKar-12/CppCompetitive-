#include<iostream>
using namespace std;

int main(){
    int m,n,p,q;
    cout<<"enter 1st array row and size:";
    cin>>m>>n;
    cout<<"enter 2nd array row and size:";
    cin>>p>>q;
    cout<<"Enter first array elements:";
    int a[m][n];
    int b[p][q];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           cin>>a[i][j];
        }
    }
    cout<<"Enter second array elements:";
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
           cin>>b[i][j];
        }
    }
    if(n==p){
        int res[m][q];
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
          res[i][j]=0;
          for(int k=0;k<n;k++){
            res[i][j]+=a[i][k]*b[k][j];
          }
        }
    }
    cout<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
           cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    }else{
        cout<<"not applicable";
    }
    
    return 0;
}
