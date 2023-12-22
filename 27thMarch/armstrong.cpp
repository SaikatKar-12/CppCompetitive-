#include <iostream>
using namespace std;

int main()
{
    int n, rem, sum=0,num;
    for (int i = 1; i <= 500; i++)
    {
        n=i;
        while(n>0)
        {
            rem = n % 10;
            sum = sum + rem * rem * rem;
            n /= 10;
        }
        if(i==sum) {
            cout<<" "<<i;
        }
       sum=0;
    }
    return 0;
}