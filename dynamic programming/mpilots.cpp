#include<iostream>
#include<vector>
#include<climits>
#include <cstring> 
using namespace std;
#define ll long long int
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
vector<ll> cap(10005, 0);
vector<ll> as(10005, 0);
ll dp[10005][5005];
int n;
ll calc(int i, int x) {
	if(dp[i][x] != -1) return dp[i][x];
	if(i == n) {
		return 0;
	}
	
	
	if(x == 0) {
		return dp[i][x] = calc(i+1, x+1) + as[i];
	} else if(x == n-i) {
		return dp[i][x] = calc(i+1, x-1) + cap[i];
	} else {
		return dp[i][x] = min(calc(i+1, x+1) + as[i], calc(i+1, x-1)+cap[i]);
	}
}
int main(){
    cin>>n;
	loop(i, 0, n-1) {
		cin>>cap[i]>>as[i];
	}
	memset(dp, -1, sizeof(dp));
    dp[0][0] = as[0] + calc(1, 1);
    cout<<dp[0][0];
    return 0;
}