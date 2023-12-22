#include<iostream>
#include<vector>
using namespace std;
void firstNeg(vector<int> v,int k){
    int p=-1;
    int n=v.size();
    vector<int> ans;
    for(int i=0;i<k;i++){
        if(v[i]<0){
            p=i;
            break;
        }
    }
    if(p!=-1){
        ans.push_back(v[p]);
    }else ans.push_back(-1);
    int i=1;
    int j=i+k-1;
    while(j<n){
        if(p>=i){
            ans.push_back(v[p]);
        }else{
            p=-1;
            for(int x=i;x<=j;x++){
                if(v[x]<0){
                    p=x;
                    break;
                }
            }
            if(p!=-1) ans.push_back(v[p]);
            else ans.push_back(-1);
        }
        i++;
        j++;
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
}
int main(){
    vector<int> v={2,-4,7,8,-3,1,5,6,-11,10,-21,-5};
    firstNeg(v,3);
    return 0;
}