#include<iostream>
using namespace std;

int main(){
    int arr[3][4]={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int m=3;
    int n=4;
    int x=33;
    int hi_row=m-1;
    int lo_row=0;
    int idx;
    bool flag=false;
    while(lo_row<=hi_row){
        int mid=lo_row+(hi_row-lo_row)/2;
        if(arr[mid][0]<=x && arr[mid][n-1]>=x) {
            idx=mid;
            break;
        }else if(arr[mid][0]>x) hi_row=mid-1;
        else lo_row=mid+1;
    }
    int hi=n-1;
    int lo=0;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[idx][mid]==x) {
            flag=true;
            break;
        }else if(arr[idx][mid]<x) lo=mid+1;
        else hi=mid-1;
    }
    if(flag) cout<<"present";
    else cout<<"not";
    return 0;
}