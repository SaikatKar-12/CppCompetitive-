#include<iostream>
#include<vector>
using namespace std;
int mod = 1e9 + 7;


vector<int> dp;
int f(vector<int> &coins,int x){
    if(x==0) return 1;
    if(x<0) return 0;
    
    if(dp[x]!=-1) return dp[x];
    int ans=0;
    for(int i=0;i<coins.size();i++){
            ans+=f(coins,x-coins[i]);
            ans %= mod;
    }
    return dp[x]=ans;
}
int main(){
    dp.clear();
    dp.resize(1000005,-1);
    int n,x;
    cin>>n>>x;
    vector<int> coins;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        coins.push_back(a);
    }
    cout<<f(coins,x);
    return 0;
}