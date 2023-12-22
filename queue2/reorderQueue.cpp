#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void display(queue<int> &q){
    int n=q.size();
    for(int i=0;i<n;i++){
        cout<<q.front()<<" ";
        int x=q.front();
        q.pop();
        q.push(x);
    }
    cout<<endl;
}
void reverse(queue<int> &q){
    stack<int> st;
    while(q.size()>0){
        int x=q.front();
        q.pop();
        st.push(x);
    }
    while(st.size()>0){
        int x=st.top();
        st.pop();
        q.push(x);
    }
}
void reorder(queue<int> &q){
    stack<int> st;
    int n=q.size();
    for(int i=1;i<=n/2;i++){
        int x=q.front();
        q.pop();
        st.push(x);
    }
    while(st.size()>0){
        int x=st.top();
        st.pop();
        q.push(x);
    }
    for(int i=1;i<=n/2;i++){
        int x=q.front();
        q.pop();
        st.push(x);
    }
    while(st.size()>0){
        int y=st.top();
        st.pop();
        q.push(y);
        int x=q.front();
        q.pop();
        q.push(x);
    }
    reverse(q);
}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    display(q);
    reorder(q);
    display(q);
    return 0;
}