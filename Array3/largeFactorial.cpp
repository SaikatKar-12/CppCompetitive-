#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void large_fact(vector<int>&a,int val,int* size){
    int carry=0;
    for(int j=0;j<*size;j++){
        int product=a[j]*val+carry;
        a[j]=product%10;
        carry=product/10;
    }
    while(carry>0){
        a[*size]=carry%10;
        carry=carry/10;
        (*size)++;
    }
    return;
}
int main(){
    vector<int> v(500,0);
    v[0]=1;
    int size=1;
    int x;
    cout<<"Enter number:";
    cin>>x;
    for(int i=2;i<=x;i++){
        large_fact(v,i,&size);
    }
    
    for(int i=size-1;i>=0;i--){
        cout<<v[i];
    }
    return 0;
}