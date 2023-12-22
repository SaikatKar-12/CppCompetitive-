#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    int max1,max2;
    max1=max2=INT_MIN;
    int arr[n];
    for(int i=0;i<=n-1;i++){
        cin>>arr[i];
    }
    for(int i=0;i<=n-1;i++){
       if(max1<arr[i]) {
        max2=max1;
        max1=arr[i];
        }else if(max2<arr[i] && max1!=arr[i]){
            max2=arr[i];
        }
    }
    if(max2==INT_MIN){
        cout<<"No second largest number.";
    }else {
        cout<<max2;
    }
    return 0;
}