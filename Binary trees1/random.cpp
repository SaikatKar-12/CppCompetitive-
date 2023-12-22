#include<iostream>
#include<math.h>
using namespace std;
int decToBin(int n){
        int bin=0;
        int k=0;
        
        while(n>0){
            int rem=n%2;
            bin+=rem*pow(10,k);
            k++;
            n/=2;
        }
        return bin;
    }
    int main(){
    cout<<decToBin(5);
    return 0;
}