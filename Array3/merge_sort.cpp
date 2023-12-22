#include<iostream>
using namespace std;

int main(){
    int a[]={1,4,5,8};
    int b[]={2,3,6,7,10,12};
    int c[10];
    int i=0,j=0,k=0;
    while(i<4 && j<6){
        if(a[i]<b[j]){
            c[k]=a[i];
            i++;
            k++;
            c[k]=b[j];
            j++;
            k++;
        }else{
            c[k]=b[j];
            j++;
            k++;
            c[k]=a[i];
            i++;
            k++;
        }
    }
    if(i>=4){
        while(j<6){
            c[k]=b[j];
            j++;
            k++;
        }
    }
     if(j==6){
        while(i<4){
            c[k]=a[i];
            i++;
            k++;
        }
    }
    for(int i=0;i<10;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i = m - 1;
//         int j = n - 1;
//         int k = n + m - 1;
//         while (i >= 0 && j >= 0) {
//             if (nums1[i] > nums2[j]) {
//                 nums1[k--] = nums1[i--];
//             } else {
//                 nums1[k--] = nums2[j--];
//             }
//         }
//         while (j >= 0) {
//             nums1[k--] = nums2[j--];
//         }
//     }
// };