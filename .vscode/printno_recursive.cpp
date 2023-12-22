#include<iostream>
using namespace std;
void printNos(int N) {
        if (N <= 0) {
            return;
        } else {
            cout << N << " ";

            // recursive call of the function
            printNos(N - 1);
        }
    }
int main(){
    int N=10;
    printNos(N);
    return 0;
}