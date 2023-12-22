#include<iostream>
using namespace std;
void display(int a[]){
    for(int i=0;i<=4;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void change(int b[]){
    b[0]=100;// array is passed as reference in function ,that's why value can be updated
    // b or a are actually like pointers 
    //b and a points to the same array arr[]
}
int main(){
    int arr[]={2,5,6,3,4};
    display(arr);
    change(arr);
    display(arr);
    return 0;
}