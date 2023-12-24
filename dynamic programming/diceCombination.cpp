#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#define mod 1000000007
using namespace std;
vector<int> dp;
int f(int n){
    if(n==0) return 1;
    int count=0;
    if(dp[n]!=-1) return dp[n];
    for(int i=1;i<=6;i++){
        if(n-i<0) continue;
        count=(count% mod + f(n-i)% mod)%mod;
    }
    return dp[n]=count%mod;
}
int fbu(int n){
    dp[0]=1;
    for(int k=1;k<=n;k++){
        int count=0;
        for(int i=1;i<=6;i++){
            if(k-i<0) break;
            count=(count% mod + dp[k-i]% mod)%mod;
        }
        dp[k]=count%mod;
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(1000005,-1);
    cout<<fbu(n)<<endl;
    return 0;
}