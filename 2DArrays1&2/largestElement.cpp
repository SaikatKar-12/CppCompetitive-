#include<iostream>
#include<climits>
using namespace std;

int main(){
    int arr[2][3]={{7,4,19},{35,23,2}};
    int max=INT_MIN;
    for(int i=0;i<=1;i++){
        for(int j=0;j<=2;j++){
            if(max<arr[i][j]) max=arr[i][j];
        }
    }
    cout<<max;
    return 0;
}