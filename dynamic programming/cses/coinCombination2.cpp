#include<iostream>
#include<vector>
using namespace std;
int mod = 1e9 + 7;


vector<vector<int>> dp;
int f(vector<int> &coins,int x,int curr){
    if(x==0) return 1;
    if(x<0) return 0;
    
    if(dp[x][curr]!=-1) return dp[x][curr];
    int ans=0;
    for(int i=0;i<coins.size();i++){
        if(coins[i]>=curr){
            ans+=f(coins,x-coins[i],coins[i]);
            ans %= mod;
        }    
    }
    return dp[x][curr]=ans;
}
int main(){
    int n,x;
    cin>>n>>x;
    dp.clear();
   dp.resize(x + 1, vector<int>(1000005, -1));
    vector<int> coins;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        coins.push_back(a);
    }
    cout<<f(coins,x,0);
    return 0;
}