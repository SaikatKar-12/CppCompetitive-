#include<iostream>
#include<vector>
// #include <algorithm>
using namespace std;

int main(){
   vector<int> v;
    v.push_back(5);
    v.push_back(9);
    v.push_back(2);
    v.push_back(6);
    v.push_back(1);
    v.push_back(7);
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
     return 0;
}