#include<iostream>
using namespace std;
void squares(int n){
    int num;
    for(int i=1;i<=n;i++){
        num=i*i;
        cout<<num<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    squares(n);
    return 0;
}