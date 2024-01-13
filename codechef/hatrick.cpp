#include<iostream>
#include<vector>
using namespace std;
void f(vector<char> &a){
    int count=0;
    for(int i=0;i<a.size();i++){
        
        if(a[i]=='W'){
            count++;
        }else{
            count=0;
        }
        if(count==3){
            cout<<"YES\n";
            return;
        } 
    }
    cout<<"NO\n";
    return;
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    vector<char> a;
	    for(int i=0;i<6;i++){
	        char ch;
	        cin>>ch;
	        a.push_back(ch);
	    }
	    f(a);
	}

}
