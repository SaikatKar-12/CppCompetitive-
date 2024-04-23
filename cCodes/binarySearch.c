#include<stdio.h>
int binarySearch(int arr[],int left,int right,int target){
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]>target) right=mid-1;
        else left=mid+1;
    }
    return -1;
}
int main(){
    int arr[]={2,3,4,5,6,7,8,9};
    int a=binarySearch(arr,0,7,6);
    printf("%d ",a);
    return 0;
}