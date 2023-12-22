#include<iostream>
#include<vector>
using namespace std;
void reversePart(int i,int j,vector<int>&v){
    int temp;
    while(i<=j){
        temp=v[i];
        v[i]=v[j];
        v[j]=temp;
        i++;
        j--;
    }
}
int main(){
     vector<int> v;
    int n;
    cout<<"Enter array size:";
    cin>>n;
    cout<<"Enter array elements:";
    for(int i=0;i<=n-1;i++){
        int q;
        cin>>q;
        v.push_back(q);
    }
   int k;
   cout<<"Enter rotation:";
   cin>>k;
   if(k>n) k=k%n;
   reversePart(0,n-k-1,v);
   reversePart(n-k,n-1,v);
   reversePart(0,n-1,v);
     for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
    return 0;
}