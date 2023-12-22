#include<iostream>
#include<string>
#include<vector>
using namespace std;
void subSeq(int arr[],int n,int idx,vector<int> v,int k){
    if(idx==n){
        if(v.size()==k){
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    subSeq(arr,n,idx+1,v,k);
    v.push_back(arr[idx]);
    subSeq(arr,n,idx+1,v,k);
}
int main(){
    int arr[]={1,2,3,4,5};
    vector<int> v;
    subSeq(arr,5,0,v,4);
    return 0;
}