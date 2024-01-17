#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<vector<int>> dp;
int f(vector<int>&prices,vector<int> &pages,int i,int j,int x){
    if(x<0) return INT_MIN;
    if(i>=prices.size()) return 0;
    if(dp[i][x]!=-1) return dp[i][x];
    return dp[i][x]=max((pages[j]+f(prices,pages,i+1,j+1,x-prices[i])),(f(prices,pages,i+1,j+1,x)));
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> prices;
    vector<int> pages;
    dp.clear();
    dp.resize(1005,vector<int>(100005,-1));
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        prices.push_back(a);
    }
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        pages.push_back(a);
    }
    cout<<f(prices,pages,0,0,x);
    return 0;
}