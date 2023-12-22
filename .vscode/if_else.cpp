#include <bits/stdc++.h>
using namespace std;
int main()
{
if (0) // Replace 1 with 0 and see the magic
{
    label_1: cout <<"Hello ";
    
    // Jump to the else statement after 
    // executing the above statement
    goto label_2;
}
else
{
    // Jump to 'if block statement' if 
    // the Boolean condition becomes false
    goto label_1;

    label_2: cout <<"Geeks";
}
return 0;
}