#include<iostream>
using namespace std;
#define ll long long int 
ll dp[2005][2005][10];
ll kordered(int a[],int b[],int m,int n,int i,int j,int k){
	if(n==i || m==j){
		return 0;
	}
	if(dp[i][j][k]!=-1){
		return dp[i][j][k];
	}
	ll res=0;
	if(a[i]==b[j]){
		res=1+kordered(a,b,m,n,i+1,j+1,k);
	}else{
		if(k>0){
			res=1+kordered(a,b,m,n,i+1,j+1,k-1);

		}
		res=max(res,kordered(a,b,m,n,i+1,j,k));
		res=max(res,kordered(a,b,m,n,i,j+1,k));
	}
	return dp[i][j][k]=res;
}
int main(){
    
    return 0;
}