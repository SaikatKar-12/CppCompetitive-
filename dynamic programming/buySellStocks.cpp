#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int dp[1005][105][2];
    int f(vector<int>& a,int i,int k,bool on){
        if(i>=a.size()) return 0;
        int res;
        if(dp[i][k][on]!=-1) return dp[i][k][on];
        res=f(a,i+1,k,on);
        if(k>0 && on==true){
            res=max(res,a[i]+f(a,i+1,k-1,false));
        }else if(k>0 && on==false){
            res=max(res,-a[i]+f(a,i+1,k,true));
        }
        return dp[i][k][on]=res;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return f(prices,0,k,false);
    }
};
int main(){
    
    return 0;
}