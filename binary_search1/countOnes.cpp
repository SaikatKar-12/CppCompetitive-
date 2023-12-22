#include<iostream>
using namespace std;

int main(){
    int arr[]={0,0,0,1,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int lo=0;
    int hi=n-1;
    int x;
    bool flag=false;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==1 ) {
            if(arr[mid-1]!=1){
                flag=true;
                x=mid;
                break;
            }else hi=mid-1;
            
        }else if(arr[mid]>x) hi=mid-1;
        else lo=mid+1;
    }
    if(flag==false) x=hi;
    cout<<n-x;
    return 0;
}