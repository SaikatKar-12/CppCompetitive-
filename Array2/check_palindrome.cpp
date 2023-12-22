#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>&a){
    for(int i=0;i<a.size();i++){
        cout<<a.at(i)<<" ";
    }
    cout<<endl;
}
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
    //  vector<int> u(v.size());
    // for(int i=0;i<=v.size();i++){
    //     u[i]=v[n-i-1];
    // }
    bool flag=true;
    // for(int i=0;i<=v.size()-1;i++){
    //     if(v[i]!=u[i]) flag=false;
    // }
    for(int i=0;i<=v.size()-1;i++){
        if(v[i]!=v[n-i-1]) flag=false;
    }
    if(flag==true){
        cout<<"It is a palindrome";
    }else{
        cout<<"Not a palindrome";
    }
    return 0;
}