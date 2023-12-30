#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
#define ll long long int
using namespace std;
vector<vector<ll> > dp;
ll f(vector<int> &wts,vector<int> &val,int i,int W){
    if(i==wts.size()|| W<=0) return 0;
    if(dp[i][W]!=-1) return dp[i][W];
    return dp[i][W]=max((W-wts[i]>=0)?(f(wts,val,i+1,W-wts[i])+val[i]):INT_MIN,f(wts,val,i+1,W));
    
}

// ll f(vector<int> &wts, vector<int> &val, int idx, int W) {
//     if(idx == wts.size()) return 0;
//     if(dp[idx][W] != -1) return dp[idx][W];
//     ll ans = INT_MIN;
//     // not pick
//     ans = max(ans, f(wts, val, idx+1, W));
//     // pick
//     if(wts[idx] <= W) {
//         ans = max(ans, val[idx] + f(wts, val, idx+1, W-wts[idx]));
//     }

//     return dp[idx][W] = ans;
// }
int main() {
    int n, W;
    cin>>n>>W;
    dp.clear();
    dp.resize(105, vector<ll> (100005, -1));
    vector<int> wts, val;
    for(int i = 0; i < n; i++) {
        int w, v;
        cin>>w>>v;
        wts.push_back(w);
        val.push_back(v);
    }
    cout<<f(wts,val,0,W);
    return 0;
}