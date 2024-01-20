#include<iostream>
using namespace std;
int countSetBits(int decimalNumber) {
    int count = 0;

    // Loop through each bit of the number
    while (decimalNumber > 0) {
        // Check if the least significant bit is set
        count += decimalNumber & 1;

        // Right shift the number to move to the next bit
        decimalNumber >>= 1;
    }

    return count;
}
int main(){
    cout<<countSetBits(30);
    return 0;
}