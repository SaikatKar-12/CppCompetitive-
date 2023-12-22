#include<iostream>
using namespace std;

int main(){
    bool flag=true;
    int arr[]={4,9,7,2,8};
    int n=5;
    int brr[5];
    for(int i=0;i<n;i++){
        brr[i]=arr[i];
    }
    for(int i=0;i<n-1;i++){
        bool flag1=false;
        for(int j=0;j<n-1-i;j++){
            
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag1=true;
            }
        }
        if(flag1==false){
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(i==0){
            if(brr[i]!=arr[i] && brr[i]!=arr[i+1]){
                flag=false;
                break;
            }
        }else if(i==n-1){
             if(brr[i]!=arr[i] && brr[i]!=arr[i-1]){
                flag=false;
                break;
            }
        }else{
            if(brr[i]!=arr[i] && brr[i]!=arr[i-1] && brr[i]!=arr[i+1]){
                flag=false;
                break;
            }
        }
    }
    if(flag==false){
        cout<<"NO";
    }else{
        cout<<"yes";
    }
    return 0;
}