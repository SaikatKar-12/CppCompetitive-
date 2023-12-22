// #include<iostream>
// // using namespace std;
// // shows error
// int main(){
//     int value=0;
//     double value=0.0;
//     return 0;
// }
#include<iostream>
using namespace std;
// Here we can see that more than one variables 
// are being used without reporting any error.
// That is because they are declared in the 
// different namespaces and scopes.
namespace first
{
    int value=0;
}

int main(){
    //  int value=0;
     double value=0.0;
    return 0;
}
/*
namespace first
{
    int val = 500;
}

// Global variable
int val = 100;

int main()
{
    // Local variable
    int val = 200;

    // These variables can be accessed from
    // outside the namespace using the scope
    // operator ::
    cout << first::val << '\n'; 

    return 0;
}*/