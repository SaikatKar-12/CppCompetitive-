#include<iostream>
using namespace std;
void print(int arr[],int n){
    cout<<arr[n-1]<<" ";
    if(n==1) return;
    print(arr,n-1);
}
int main(){
    int arr[]={3,4,6,7,9,13,16};
    print(arr,7);
    return 0;
}