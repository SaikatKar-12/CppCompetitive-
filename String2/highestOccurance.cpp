#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    string str;
    int ascii;
    cout<<"Enter string: ";
    getline(cin,str);
    vector<int> arr(26,0);
    for(int i=0;i<str.size();i++){
        ascii=(int)str[i];
        arr[ascii-97]++;
    }
    int max=0;
    for(int i=0;i<26;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    for(int i=0;i<26;i++){
        if(max==arr[i]){
            ascii=i+97;
            char ch=(char)ascii;
            cout<<ch<<" "<<max<<endl;
        }
    }
    return 0;
}