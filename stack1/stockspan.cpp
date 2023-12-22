#include<iostream>
#include<stack>
using namespace std;

int main(){
    int arr[]={100,80,70,81,60,75,60,85};
    int n=8;
    int pgi[8];
    stack<int> st;
    pgi[0]=1;
    st.push(0);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<n;i++){
        while(st.size()!=0 && arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(st.size()==0) pgi[i]=-1;
        else pgi[i]=st.top();
        pgi[i]=i-pgi[i];
        st.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<pgi[i]<<" ";
    }
    cout<<endl;
    return 0;
}