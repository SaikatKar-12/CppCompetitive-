#include<iostream>
#include<string.h>
using namespace std;
void generate(string s,int n,int c,int d){
    if(s.length()==n*2){
        cout<<s<<endl;
        return;
    }
    if(c<n){
        generate(s+'(',n,c+1,d);
    }
    if(d<c){
        generate(s+')',n,c,d+1);
    }
}
int main(){
    generate("",2,0,0);
    return 0;
}