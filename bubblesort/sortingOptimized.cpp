#include<iostream>
using namespace std;

int main(){
    bool flag=true;
    int arr[]={5,1,2,3,4};
    int n=5;
    for(int i=0;i<n-1;i++){
        flag=false;
        for(int j=0;j<n-1-i;j++){
            
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=true;
            }
        }
        if(flag==false){
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}