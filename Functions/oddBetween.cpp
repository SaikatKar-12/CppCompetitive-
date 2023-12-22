#include<iostream>
using namespace std;
void oddBetween(int a,int b){
    for(int i=min(a,b);i<=max(a,b);i++){
        if(i%2!=0){
            cout<<i<<endl;
        }
    }
}
int main(){
    int a,b;
    cout<<"Enter two numbers:";
    cin>>a>>b;
    oddBetween(a,b);
    return 0;
}