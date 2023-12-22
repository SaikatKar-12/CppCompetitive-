#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &a){
    for(int i=0;i<=a.size()-1;i++){
        cout<<a[i]<<" ";
    }
}
void sort01(vector<int> &b){
  int i=0;
  int j=b.size()-1;
  while(i<j){
    if(b[j]==1) j--;
    if(b[i]==0) i++;
    if(i>j) break;
    if(b[i]==1 && b[j]==0){
        int temp;
        temp=b[i];
        b[i]=b[j];
        b[j]=temp;
        i++;
        j--;
    }
  }
}
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    display(v);
    cout<<endl;
    sort01(v);
    display(v);
    return 0;
}