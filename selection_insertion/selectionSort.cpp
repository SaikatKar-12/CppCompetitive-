#include<iostream>
#include<climits>
using namespace std;

int main(){
    int arr[]={5,4,2,1,3};
    int n=5;
    for(int ele : arr){
        cout<<ele<<" ";
    }
    cout<<endl;
    //insertion sort
    for(int i=0;i<n-1;i++){
        int min=INT_MAX;
        int minIndex=-1;
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
    for(int ele : arr){
        cout<<ele<<" ";
    }
    return 0;
}