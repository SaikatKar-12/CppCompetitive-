#include<iostream>
using namespace std;

int main(){
    int arr[5][6]={{0,0,0,1,1,1},{0,0,1,1,1,1},{0,0,0,0,0,1},{0,1,1,1,1,1},{0,0,0,1,1,1}};
    int m=5;
    int n=6;
    int firstIndex=-1;
    int maxr=-1;
    int maxOnes=0;
    for(int i=0;i<m;i++){
        int lo=0;
        int hi=n-1;
        int countOnes=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[i][mid]==1){
                if(mid==0){
                    firstIndex=mid;
                    break;
                }else if(arr[i][mid-1]!=1){
                    firstIndex=mid;
                    break;
                }else hi=mid-1;
            }else lo=mid+1;
        }
        countOnes=n-firstIndex;
        if(countOnes>maxOnes){
            maxOnes=countOnes;
            maxr=i;
        }
        
    }
    cout<<maxr<<" "<<maxOnes;
    return 0;
}