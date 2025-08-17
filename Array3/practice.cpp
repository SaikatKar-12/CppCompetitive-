#include<iostream>
#include<vector>
using namespace std;
int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    int a =0;
    int b=v.size()-1;
    cout<<"hello"<<endl;
    while(a<b){
        if(v[a]==1 && v[b]==0){
            v[a]=0;
            v[b]=1;
            a++;
            b--;
        }else if(v[a]==0){
            a++;
        }else if(v[b]==1){
            b--;
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}