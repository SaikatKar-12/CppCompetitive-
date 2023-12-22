#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &a){
    for(int i=0;i<=a.size()-1;i++){
        cout<<a[i]<<" ";
    }
}
void sort(vector<int> &b){
  int i=0;
  int j=b.size()-1;
  while(i<j){
    if(b[j]>=0) j--;
    if(b[i]<0) i++;
    if(i>j) break;
    if(b[i]>=0 && b[j]<0){
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
    v.push_back(3);
    v.push_back(-2);
    v.push_back(7);
    v.push_back(1);
    v.push_back(-8);
    v.push_back(5);
    v.push_back(-4);
    v.push_back(-1);
    display(v);
    cout<<endl;
    sort(v);
    display(v);
    return 0;
}