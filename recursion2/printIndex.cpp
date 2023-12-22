#include<iostream>
using namespace std;
int printIdx(int arr[],int n,int x){
    if(arr[n-1]==x) return n-1;
    if(n==1) return -1;
    printIdx(arr,n-1,x);
}
int main(){
    int arr[]={3,4,6,7,9,13,16};
    cout<<printIdx(arr,7,14);
    return 0;
}