#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

bool cmp(int x,int y){
    return x>y;
}

ll minCostToBreakGrid(int n,int m,vector<ll> &vertical,vector<ll> &horizontal){
    sort(vertical.begin(),vertical.end(),cmp);
    sort(horizontal.begin(),horizontal.end(),cmp);
    int hz=1;
    int vr=1;
    int h=0,v=0;
    ll ans=0;
    while(h<horizontal.size() && v<vertical.size()){
        if(vertical[v]>horizontal[h]){
            ans+=vertical[v]*vr;
            hz++;
            v++;
        }else{
            ans+=horizontal[h]*hz;
            vr++;
            h++;
        }
    }
    while(h<horizontal.size()){
        ans+=horizontal[h]*hz;
        vr++;
        h++;
    }
    while(v<vertical.size()){
        ans+=vertical[v]*vr;
        hz++;
        v++;
    }
    return ans;
}

int main(){
    int m=6,n=4;
    vector<ll> hori ={2,1,3,1,4};
    vector<ll> vert={4,1,2};
    cout<<minCostToBreakGrid(n,m,hori,vert);
    return 0;
}