#include<iostream>
using namespace std;
void sum1(int sum,int n){
    if(n==0){
        cout<<sum<<endl;
        return;
    }
    sum1(sum+n,n-1);
}
int sum2(int n){
    if(n==0){
        return 0;
    }
    return n+ sum2(n-1);
}
int main(){
    //sum1(0,10);
    int ans=sum2(10);
    cout<<ans;
    return 0;
}