#include<iostream>
using namespace std;
void sumTriangle(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    if(n==1) return ;
    cout<<endl;
    for(int i=0;i<n-1;i++){
        arr[i]+=arr[i+1];
    }
    sumTriangle(arr,n-1);
}
int main(){
    int arr[]={3,4,6,7,9,13,16};
    sumTriangle(arr,7);
    return 0;
}