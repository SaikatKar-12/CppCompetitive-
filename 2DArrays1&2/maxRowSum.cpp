#include<iostream>
#include<climits>
using namespace std;

int main(){
    int arr[4][3]={{7,4,19},{3,23,2},{3,5,700},{11,29,19}};
    int sum=0;
    int max_sum;
    int max_row;
    for(int i=0;i<=3;i++){
        max_sum=sum;
        sum=0;
        for(int j=0;j<=2;j++){
            sum+=arr[i][j];
        }
        if(max_sum<sum){
            max_sum=sum;
            max_row=i+1;
        }
    }
    cout<<max_row;
    return 0;
}