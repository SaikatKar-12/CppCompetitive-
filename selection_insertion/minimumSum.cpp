#include<iostream>
#include<climits>
using namespace std;

int main(){
    int arr[]={5,7,9,1,3,4,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int min=INT_MAX;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]<min){
                min=arr[i]+arr[j];
            }
        }
    }
    cout<<"minimum sum : "<<min;
    return 0;
}