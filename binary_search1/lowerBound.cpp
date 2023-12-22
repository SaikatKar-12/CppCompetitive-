#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,4,8,13,16,19,25,31};
    int n=9;
    int x=25;
    int lo=0;
    int hi=n-1;
    int mid;
    bool flag=false;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        if(arr[mid]==x){
            flag=true;
            cout<<arr[mid-1];
            break;
        }else if(arr[mid]<x) lo =mid+1;
        else hi=mid-1;
    }
    if(flag==false) cout<<arr[hi];
    return 0;
}