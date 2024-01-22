#include<iostream>
#include<vector>
using namespace std;
void printvec(vector<int> v){
    int i=0;
    int j=i+3-1;
    while(j<v.size()){
        for(int k=i;k<=j;k++){
            cout<<v[k]<<" ";
        }
        cout<<endl;
        i++;
        j++;
    }
}
int main(){
    vector<int> v={2,3,5,6,8,6,4,1,3,7,2,5,8};
    printvec(v);
    return 0;
}