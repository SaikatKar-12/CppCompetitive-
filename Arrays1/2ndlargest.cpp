#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    int arr[n];
    for(int i=0;i<=n-1;i++){
        cin>>arr[i];
    }
    int max=INT_MIN;
    for(int i=0;i<=n-1;i++){
        if(max<arr[i]){
            max=arr[i];
        }
        
    }
    int smax=INT_MIN;
     for(int i=0;i<=n-1;i++){
        if(smax<arr[i] && max!=arr[i]){
            smax=arr[i];
        }
        
    }
    cout<<max<<" "<<smax;
    return 0;
}