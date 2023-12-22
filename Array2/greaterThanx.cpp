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
    cout<<"Enter x:";
    cin>>x;
    int count=0;
    for(int i=0;i<=v.size()-1;i++){
        if(v[i]>x) count++;
    }
    cout<<count<<" Numbers greater than x ";
    return 0;
}