#include<iostream>
using namespace std;
void power(int n){
    if(n==1) {
    cout<<"true";
    return;
    }
    else if(n%2!=0) {
        cout<<"false";
        return;
    }
    else power(n/2);
}
int main(){
    power(69);
    return 0;
}