#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    int n;
    cout<<"Enter array size:";
    cin>>n;
    cout<<"Enter array elements:";
    for(int i=0;i<=n-1;i++){
       int q;
       cin>>q;
       v.push_back(q);
    }
    int x;
    cout<<"Enter target:";
    cin>>x;
    int count=0;
    for(int i=0;i<=n-3;i++){
        for(int j=i+1;j<=n-2;j++){
            for(int k=j+1;k<=n-1;k++){
                if(v[i]+v[j]+v[k]==x){
                  cout<<"("<<v[i]<<","<<v[j]<<","<<v[k]<<")";
                }
            }
        }
    }
    
    return 0;
}