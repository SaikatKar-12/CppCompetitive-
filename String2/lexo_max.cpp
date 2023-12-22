#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

int main(){
    string str;
    cout<<"Enter string: ";
    getline(cin,str);
    stringstream ss(str);
    vector<string> v;
    string temp;
    while(ss>>temp){
        v.push_back(temp);
    }
    int n=v.size();
    sort(v.begin(),v.end());
    cout<<v[n-1];
    return 0;
}