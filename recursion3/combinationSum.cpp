#include<iostream>
#include<vector>
using namespace std;
void combination(vector<int> v,int arr[],int n,int target,int idx){
    if(target==0){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(target<0) return;
    for(int i=idx;i<n;i++){
        v.push_back(arr[i]);
        combination(v,arr,n,target-arr[i],i);
        v.pop_back();
    }
}
int main(){
    vector<int> v;
    int arr[]={2,3,5};
    int target=8;
    combination(v,arr,3,8,0);
    return 0;
}