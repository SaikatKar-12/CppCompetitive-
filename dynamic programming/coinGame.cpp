#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<bool> dp;
bool f(int n,int k,int l){
    if(n==0) return false;
    if(n==1 || n==k ||n==l) return true;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=!(f(n-1,k,l)&& f(n-k,k,l)&&f(n-l,k,l));
}

int main(){
    int k,m,l;
    cin>>k>>l>>m;
    dp.clear();
    dp.resize(1000005,0);
    dp[1]=1;
    dp[k]=1;
    dp[l]=1;
    for(int i=2;i<=1000000;i++){
        if(i==l || i==k) continue;
        dp[i]=!(dp[i-1] && ((i-k>=1)?dp[i-k]:1 )&& ((i-l>=1)?dp[i-l]:1));
    }
    for(int i=0;i<m;i++){
        int n;
        cin>>n;
        if(dp[n]==1) cout<<"A";
        else cout<<"B";
    }
    return 0;
}