#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    vector<int> a;
    a.push_back(2);
    a.push_back(6);
    a.push_back(7);
    a.push_back(9);
    a.push_back(5);
    a.push_back(3);
   
    bool flag=true;
    int n=a.size();
    for(int i=0;i<=v.size()-1;i++){
        int j;
        for(j=0;j<=a.size()-1;j++){
            if(v[i]==a[j]) break;
        }
        if(j==n) flag=false;
    }
    if(flag==true) cout<<"is a subset";
    else cout<<"Not a subset";
}