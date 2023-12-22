#include<iostream>
using namespace std;
void print(int i,int n){
    if(i>n) return;
    cout<<i<<endl;
    print(i+1,n);
}
int main(){
    print(1,9);
    return 0;
}