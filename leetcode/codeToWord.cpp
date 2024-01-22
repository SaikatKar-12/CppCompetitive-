#include<iostream>
using namespace std;
const char hashTable[10][5]
    = { "",    "",    "abc",  "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz" };
int main(){
    string s ="7555266338";
    int occ=0;
    string ans="";
    for(int i=0;i<s.size();i++){
        if(i!=s.size()-1 && s[i+1]==s[i]){
            occ++;
        }else{
            occ++;
            int idx=s[i]-'0';
            string a="";
            a+=hashTable[idx][occ-1];
            ans+=a;
            occ=0;
        }
    }
    cout<<ans;
    return 0;
}