#include<iostream>
using namespace std;

int main(){
    int arr[]={0,0,1,1,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int lo=0;
    int hi=n-1;
    int x;
    bool flag=false;
    int firstIndex=-1;
    while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]==1){
                if(mid==0){
                    firstIndex=mid;
                    break;
                }else if(arr[mid-1]!=1){
                    firstIndex=mid;
                    break;
                }else hi=mid-1;
            }else lo=mid+1;
        }
        cout<<n-firstIndex;
    return 0;
}