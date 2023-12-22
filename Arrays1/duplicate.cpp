#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    bool flag=false;
    int arr[n];
    for(int i=0;i<=n-1;i++){
        cin>>arr[i];
    }
    for(int i=0;i<=n-1;i++){
        for(int j=i+1;j<=n-1;j++){
            if(arr[i]==arr[j]){
                flag=true;
            }
        }
    }
    if(flag==true) cout<<"Duplicate present";
    else cout<<"no duplicates";
    return 0;
}