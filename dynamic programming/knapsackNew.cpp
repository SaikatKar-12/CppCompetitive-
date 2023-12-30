#include <iostream>
#include <vector>
#include <climits>
#include<algorithm>
#define ll long long int
using namespace std;

vector<vector<ll> > dp;

ll f(vector<int> &wts, vector<int> &val, int idx, int W) {
    if(idx == wts.size()) return 0;
    if(dp[idx][W] != -1) return dp[idx][W];
    // ll ans = INT_MIN;
    // // not pick
    // ans = max(ans, f(wts, val, idx+1, W));
    // // pick
    // if(wts[idx] <= W) {
    //     ans = max(ans, val[idx] + f(wts, val, idx+1, W-wts[idx]));
    // }

    // return dp[idx][W] = ans;
    return dp[idx][W]= max((W-wts[idx]>=0)?(val[idx]+f(wts,val,idx+1,W-wts[idx])):INT_MIN,f(wts,val,idx+1,W));
}
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