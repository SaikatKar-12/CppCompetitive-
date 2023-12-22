#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        int pivot=-1;
        //finding pivot
        if(n==1){
            if(nums[0]==target) return 0;
            else return -1;
        }else if(n==2){
            if(nums[0]==target) return 0;
            else if(nums[1]==target) return 1;
            else return -1;
        }
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(mid==0) lo=mid+1;
            else if(mid==n-1) hi=mid-1;
            else if(nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1]) pivot=mid;
            else if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]) pivot=mid+1;
            else if(nums[mid]>nums[n-1]) lo=mid+1;
            else hi=mid-1;
        }
        //binary search
        if(target>nums[0] && target<nums[pivot-1]){
             lo=0;
             hi=pivot-1;
             while(lo<=hi){
                 int mid=lo+(hi-lo)/2;
                 if(nums[mid]==target) return mid;
                 else if(nums[mid]>target) hi=mid-1;
                 else lo=mid+1;
             }
        }
        else if(target>nums[pivot] && target<nums[n-1]){
             lo=pivot;
             hi=n-1;
             while(lo<=hi){
                 int mid=lo+(hi-lo)/2;
                 if(nums[mid]==target) return mid;
                 else if(nums[mid]>target) hi=mid-1;
                 else lo=mid+1;
             }
        }
        return -1;
    }
int main(){
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    int target=3;
    int res=search(nums,target);
    cout<<res;
    return 0;
}