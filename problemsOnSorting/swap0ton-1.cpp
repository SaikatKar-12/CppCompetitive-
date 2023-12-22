#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    int arr[]={34,19,8,9,232};
    int n=5;
    vector<int> v(n,0);
    int x=0;
    for(int i=0;i<n;i++){
        int min=INT_MAX;
        int minIndex;
        for(int j=0;j<n;j++){
            if(v[j]==1) continue;
            else if(arr[j]<min){
                min=arr[j];
                minIndex=j;
            }
        }
        arr[minIndex]=x;
        x++;
        v[minIndex]=1;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}