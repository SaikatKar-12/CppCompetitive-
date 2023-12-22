#include<iostream>
using namespace std;
int sumOdd(int a,int b){
    int ans=0;
    if(a>b) return 0;
    else if(a%2==0){
        ans+=sumOdd(a+1,b);
    }else{
        ans+=a+sumOdd(a+1,b);
    }
}
int main(){
    int ans=sumOdd(2,11);
    //3 5 7 9
    cout<<ans;
    return 0;
}