#include<iostream>
using namespace std;

int main(){
    int arr[5][5]={{1,2,3,4,8},{1,2,3,4,5},{5,2,3,7,5},{1,9,3,4,5},{1,2,3,2,5}};
    int row=sizeof(arr)/sizeof(arr[0]);

    int sum1=0;
    int sum2=0;

    for(int i=0;i<row;i++){
        for(int j=0;j<row;j++){
            if(i==j) sum1+=arr[i][j];
            if(i+j==row-1) sum2+=arr[i][j];
        }
        
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<row;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<abs(sum1-sum2);
    return 0;
}