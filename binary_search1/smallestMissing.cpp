#include<iostream>
using namespace std;

int main(){
    int arr[]={0,1,2,3,4,5,7,10,14};
    int n=8;
    int lo=0;
    int hi=n-1;
    int mid;
    int ans=-1;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        if(mid==arr[mid]){
            lo=mid+1;
        }else{
            ans=mid;
            hi=mid-1;
        }
    }
    cout<<ans;
    return 0;
}