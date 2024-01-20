#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int findMax(vector<int>& nums){
        int max=INT_MIN;
        int idx=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max) {
                max=nums[i];
                idx=i;
            }
        }
        return idx;
    }
    int minimumArrayLength(vector<int>& nums) {
        while(nums.size()>1 ){
            int i=0;
            int j=1;
            while(nums[j]==0){
                j++;
                if(j>=nums.size()) break;
            }
            while(nums[i]==nums[j]){
                if(j==nums.size()-1|| nums[j+1]==0) break;
                else j++;
            }
            if(j>=nums.size()) break;
            int mod;
            if(nums[j]>nums[i]){
                //cout<<"hello";
                mod=nums[i]%nums[j];
            }else{
                //cout<<"hello";
                mod=nums[j]%nums[i];
            }
            //int mod=(j>i)?(nums[i]%nums[j]):(nums[j]%nums[i]);
            nums.push_back(mod);
            nums.erase(nums.begin() + j);
            nums.erase(nums.begin() + i);
            for(auto x:nums){
                cout<<x<<" ";
            }
            cout<<endl;
            
        }
        return nums.size();
    }
int main(){
    vector<int> vec = {5,2,2,2,9,10};
    //vec.erase(vec.begin() + 2);
    cout<<minimumArrayLength(vec);
    //cout<<1%3;
    return 0;
}