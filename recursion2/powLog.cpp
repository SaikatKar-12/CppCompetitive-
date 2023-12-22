#include<iostream>
using namespace std;
int pow(int a,int n){
    if(n==1) return a;
    int ans =pow(a,n/2);
    if(n%2==0) return ans*ans;
    else return a*ans*ans;
}
int main(){
    cout<<pow(3,5);
    return 0;
}