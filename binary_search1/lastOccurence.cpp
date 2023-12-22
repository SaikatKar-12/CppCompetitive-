#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,2,2,2,2,2,2,2,2,7,8,9,11,12,13,14,15,16};
    int n=sizeof(arr)/sizeof(arr[0]);
    int lo=0;
    int hi=n-1;
    int x=14;
    bool flag=false;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==x ) {
            if(arr[mid+1]!=x){
                flag=true;
                cout<<mid;
                break;
            }else lo=mid+1;
            
        }else if(arr[mid]>x) hi=mid-1;
        else lo=mid+1;
    }
    if(flag==false) cout<<lo<<" from lo";
    return 0;
}