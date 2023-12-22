#include<iostream>
using namespace std;

int main(){
    int arr[]={1,3,4,5,8,9,14,16,17,19,24,25};
    int lo=0;
    int hi=1;
    int target=15;
    bool flag=false;
    while(arr[hi]<target){
        lo=hi;
        hi=hi*2;
    }
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==target) {
            flag=true;
            break;
        }else if(arr[mid]<target) lo=mid+1;
        else hi=mid-1;

    }
    if(flag) cout<<"yes";
    else cout<<"No";
    return 0;
}