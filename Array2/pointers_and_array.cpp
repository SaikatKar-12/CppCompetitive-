#include<iostream>
using namespace std;

int main(){
    int arr[]={2,5,6,3,4};
    int* ptr=arr;//declaring
//    for(int i=0;i<=4;i++){
//     cout<<ptr[i]<<" ";
//    }
 for(int i=0;i<=4;i++){
    cout<<*ptr<<" ";
    ptr++;
   }
    return 0;
}