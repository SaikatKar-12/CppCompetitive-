#include<iostream>
#include<limits.h>
using namespace std;
int maxarr(int arr[],int n,int idx){
    if(idx==n) return INT_MIN;
    return max(arr[idx],maxarr(arr,n,idx+1));
}
int main(){
    int arr[]={2,7,4,6,1,8,9,3,16};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<maxarr(arr,n,0);
    return 0;
}