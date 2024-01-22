#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int minimumPushes(string word) {
        unordered_map<char,int> freq;
        for(auto x:word){
            freq[x]++;
        }
        vector<int> occ;
        for(auto ele:freq){
            int a=ele.second;
            occ.push_back(a);
        }
        sort(occ.begin(),occ.end(),greater<int>());
        int req=1;
        int ans=0;
        int curr=2;
        for(auto x:occ){
            ans+=x*req;
            curr++;
            if(curr==10){
                curr=2;
                req++;
            }
        }
        return ans;
}
int main(){
    
    return 0;
}