#include<iostream>
using namespace std;

int main(){
    int arr[2][3]={1,2,3,4,5,6};
   
    for(int i=0;i<=1;i++){
        for(int j=0;j<=2;j++){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    int trans[3][2];
    for(int j=0;j<=2;j++){
        for(int i=0;i<=1;i++){
           trans[j][i]=arr[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<=2;i++){
        for(int j=0;j<=1;j++){
           cout<<trans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}