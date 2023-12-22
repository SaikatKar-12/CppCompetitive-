#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5,6,7,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int lo=0;
    int hi=n-1;
    bool flag=false;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==mid){
            if(arr[mid-1]!=mid-1){
                flag=true;
                cout<<arr[mid];
                break;
            }else hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    if(flag==false) cout<<lo<<" from low";
    return 0;
}