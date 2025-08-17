class Solution {
public:
    void sortColors(vector<int>& v) {
        int lo=0;
        int mid=0;
        int hi=v.size()-1;
        while(mid<=hi){
            if(v[mid]==2){
                int temp=v[mid];
                v[mid]=v[hi];
…            }
        }
    }
};