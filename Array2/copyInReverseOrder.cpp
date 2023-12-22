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
    vector<int> u(v.size());
    for(int i=0;i<=v.size();i++){
        u[i]=v[n-i-1];
    }
    cout<<"New array is"<<endl;
    for(int i=0;i<u.size();i++){
        cout<<u.at(i)<<" ";
    }
    return 0;
}