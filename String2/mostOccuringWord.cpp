#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

int main(){
    string str;
    int ascii;
    cout<<"Enter string: ";
    getline(cin,str);
    vector<string> arr;
    string temp;
    stringstream ss(str);
    while(ss>>temp){
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    int count=1;
    int maxCount=0;
    for(int i=1;i<arr.size();i++){
        if(arr[i]==arr[i-1]) count++;
        else count=1;
        maxCount=max(maxCount,count);
    }
    for(int i=1;i<arr.size();i++){
        if(arr[i]==arr[i-1]) count++;
        else count=1;
        if(maxCount==count) cout<<arr[i]<<" "<<maxCount<<endl;
    }
    return 0;
}