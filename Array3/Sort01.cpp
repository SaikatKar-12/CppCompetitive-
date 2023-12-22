#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &a){
    for(int i=0;i<=a.size()-1;i++){
        cout<<a[i]<<" ";
    }
}
void sort01(vector<int> &b){
    int n=b.size();
    int num0=0;
    int num1=0;
    for(int i=0;i<=b.size()-1;i++){
        if(b[i]==0) num0++;
        else num1++;
    }
    for(int i=0;i<=b.size()-1;i++){
        if(i<num0){
            b[i]=0;
        }else{
            b[i]=1;
        }
    }
}
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    display(v);
    cout<<endl;
    sort01(v);
    display(v);
    return 0;
}