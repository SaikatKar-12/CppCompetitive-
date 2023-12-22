#include<iostream>
#include<climits>
using namespace std;

int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    int l1,r1,l2,r2;
    cout<<"enter no:";
    cin>>l1>>r1>>l2>>r2;
    int sum=0;
    for(int i=min(l1,l2);i<=max(l1,l2);i++){
        for(int j=min(r1,r2);j<=max(r1,r2);j++){
            sum=sum+arr[i][j];
        }
    }
    cout<<sum;
    return 0;
}