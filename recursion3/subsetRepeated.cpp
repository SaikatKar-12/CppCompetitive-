#include<iostream>
#include<string>
#include<vector>
using namespace std;
void subset(string str,string original,vector<string>&v,bool flag){
    if(original.length()==0){
        v.push_back(str);
        return;
    }
    char ch=original[0];
    if(original.length()==1){
        subset(str+ch,original.substr(1),v,true);
        subset(str,original.substr(1),v,true);
        return;
    }
    char dh=original[1];
    if(ch==dh){
        if(flag==true){
            subset(str+ch,original.substr(1),v,true);
        }
        subset(str,original.substr(1),v,false);
    }else {
        if(flag==true){
            subset(str+ch,original.substr(1),v,true);
        }
        subset(str,original.substr(1),v,true);
    }
}
int main(){
    string str= "aaabb";
    vector<string> v;
    subset("",str,v,true);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}