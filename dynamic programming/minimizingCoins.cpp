#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

vector<int> coins;
vector<int> dp;

int f(int x){
    if(x==0) return 0;
    if(dp[x]!=-2) return dp[x];
    int result=INT_MAX;
    for(int i=0;i<coins.size();i++){
        if(x-coins[i]<0) continue;
        result=min(result,f(x-coins[i]));
    }
    if(result==INT_MAX) return dp[x]= INT_MAX;
    return dp[x]=1+result;
}

int main(){
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        int nums;
        cin>>nums;
        coins.push_back(nums);
    }
    dp.clear();
    dp.resize(1000006,-2);
    int ans=f(x);
    if(ans==INT_MAX) cout<<"-1\n";
    else cout<<ans;
    return 0;
}