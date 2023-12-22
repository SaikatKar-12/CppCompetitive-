#include<iostream>
#include<stack>
using namespace std;

int main(){
    int arr[9]={3,1,4,9,2,6,7,1,3};
    int n=9;
    int pge[9];
    stack<int> st;
    pge[0]=-1;
    st.push(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<n;i++){
        while(st.size()!=0 && st.top()<arr[i]){
            st.pop();
        }
        if(st.size()==0) pge[i]=-1;
        else pge[i]=st.top();
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<pge[i]<<" ";
    }
    cout<<endl;
    return 0;
}