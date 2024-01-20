#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void upHeapify(int hp[],int ci){
    while(ci>0){
        int pi=(ci-1)/2;
        if(hp[pi]<hp[ci]){
            swap(&hp[pi],&hp[ci]);
            ci=pi;
        }else{
            break;
        }
    }
}
void downHeapify(int hp[],int idx,int n){
    while(idx<n){
            int lc=2*idx+1;
            int rc=2*idx+2;
            if(lc>=n) break;
            int maxEl=idx;
            if(hp[lc]>hp[maxEl]) maxEl=lc;
            if(rc<n && hp[rc]>hp[maxEl]) maxEl=rc;
            if(maxEl!=idx){
                swap(&hp[maxEl],&hp[idx]);
                idx=maxEl;
            }else break;
        }
}
void heapsort(int arr[],int n){
    //int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=n/2;i>=0;i--){
        downHeapify(arr,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        downHeapify(arr,0,i);
    }
}
int main(){
    int arr[]={40,14,9,8,12,5,49,2,1,42,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    // for(int i=0;i<9;i++){
    //     upHeapify(arr,i);
    // }
    heapsort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}