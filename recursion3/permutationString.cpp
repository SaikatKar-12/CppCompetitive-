#include<iostream>
#include<string>
using namespace std;
void permutation(string str,string original){
    if(original==""){
        cout<<str<<endl;
        return;
    }
    for(int i=0;i<original.length();i++){
        char ch=original[i];
        string left=original.substr(0,i);
        string right=original.substr(i+1);
        permutation(str+ch,left+right);
    }
}
int main(){
    string str="abc";
    permutation("",str);
    return 0;
}