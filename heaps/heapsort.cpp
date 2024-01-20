#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void downheapify(int arr[],int idx,int bound){
    int lc=2*idx+1;
    int rc=2*idx+2;
    int maxEl=idx;
    if(lc<bound && arr[lc]>arr[idx]) maxEl=lc;
    if(rc<bound && arr[rc]>arr[idx]) maxEl=rc;
    if(maxEl!=idx){
        swap(&arr[maxEl],&arr[idx]);
        downheapify(arr,maxEl,bound);
    }
}
void heapsort(int arr[],int n){
    for(int i=n/2;i>=0;i--){
        downheapify(arr,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        downheapify(arr,0,i);
    }
}
int main(){
    int arr[]={5,3,7,2,1,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}