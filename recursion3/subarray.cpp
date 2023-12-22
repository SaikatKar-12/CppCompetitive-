#include<iostream>
#include<vector>
using namespace std;
void subArray(int arr[],vector<int> v,int n,int idx){
    if(idx==n){
        for(int i=0;i<v.size();i++){
            cout<<v[i];
        }
        cout<<endl;
        return;
    }
    subArray(arr,v,n,idx+1);
    if(v.size()==0 || v[v.size()-1]==arr[idx-1]){
        v.push_back(arr[idx]);
        subArray(arr,v,n,idx+1);
    }
    
}
int main(){
    vector<int> v;
    int arr[]={1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    subArray(arr,v,n,0);
    return 0;
}