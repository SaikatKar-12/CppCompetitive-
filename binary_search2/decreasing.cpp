#include<iostream>
using namespace std;

int main(){
            // 0  1 2 3 4 5 6 7
    int arr[]={12,9,8,7,5,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int lo=0;
    int hi=n-1;
    int x=15;
    int flag=false;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==x) {
            flag=true;
            break;
        }
        else if(arr[mid]<x) hi=mid-1;
        else lo=mid+1;
    }
    if(flag==true) cout<<"present";
    else cout<<"not";
    return 0;
}