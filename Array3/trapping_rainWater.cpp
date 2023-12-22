// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n=height.size();
//         //previous greatest integer
//         int prev[n];
//         prev[0]=-1;
//         int max=height[0];
//         for(int i=1;i<=n-1;i++){
//             prev[i]=max;
//             if(max<height[i]){
//                 max=height[i];
//             }
//         }
//         //next greatest integer
//         prev[n-1]=-1;
//         max=height[n-1];
//         for(int i=n-2;i>=0;i--){
//               prev[i]=min(prev[i],max);
//             if(max<height[i]){
//                 max=height[i];
//             }
//         }
        
//         //calculating trapped water
//         int water=0;
//         for(int i=0;i<=n-1;i++){
//             if(prev[i]>height[i]){
//                 water=water+(prev[i]-height[i]);
//             }
//         }
//         return water;
//     }
// };