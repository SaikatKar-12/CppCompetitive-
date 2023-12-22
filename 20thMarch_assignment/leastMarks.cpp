#include<iostream>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a<b && a<c){
        cout<<"A has the least marks";
    }else if(b<c && b<a){
        cout<<"B has the least marks";
    }else{
        cout<<"C has the least marks";
    }
    return 0;
}