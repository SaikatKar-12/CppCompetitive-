#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int getminProd(vector<int> v){
    int cn=0,cz=0,cp=0;
    int largestneg=INT_MIN;
    int prod_pos=1;
    int prod_neg=1;
    for(int i=0;i<v.size();i++){
        if(v[i]<0){
            cn--;
            prod_neg*=v[i];
            largestneg=max(largestneg,v[i]);
        }else if(v[i]==0) cz++;
        else{
            cp++;
            prod_pos*=v[i];
        }
    }
    if(cn==0){
        if(cz>0) return 0;
        else{
            auto it=min_element(v.begin(),v.end());
            return *it;
        }
    }else{
        if(cn%2!=0){
            return prod_neg*prod_pos;
        }else{
            return (prod_neg/largestneg)*prod_pos;
        }
    }
}

int main(){
    vector<int> arr ={1,4,0,7,2};
    cout<<getminProd(arr);
    return 0;
}