#include<iostream>
using namespace std;

int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
   
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    //transpose
    for(int i=0;i<=2;i++){
        for(int j=i+1;j<=2;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
       
    }
    //reverse
    for(int k=0;k<=2;k++){
       int i=0;
       int j=2;
       while(i<j){
        int temp=arr[k][i];
        arr[k][i]=arr[k][j];
        arr[k][j]=temp;
        i++;
        j--;
       }
    }
    cout<<endl;
     for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}