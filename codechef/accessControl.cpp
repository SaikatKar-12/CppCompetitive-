#include<iostream>
#include<string.h>
//#include <bits/stdc++.h>
using namespace std;

bool f(string s,int x){
    int curr=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1') curr=x;
        else if(curr>0){
            curr--;
        }else return false;
    }
    return true;
}
int main() {
	// your code goes here
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    int m,x;
	    cin>>m>>x;
	    string s;
	    cin>>s;
	    bool flag=f(s,x);
	    if(flag) cout<<"YES\n";
	    else cout<<"NO\n";
	}

}