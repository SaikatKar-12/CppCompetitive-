// Program 1
// #include <iostream>
// using namespace std;
// void fun(int arr[], unsigned int n)
// {
//     int i;
//     for (i = 0; i < n; i++)
//         cout << arr[i] << " ";
// }

// // Driver program
// int main()
// {
//     int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//     unsigned int n = sizeof(arr)/ sizeof(arr[0]);
//     fun(arr, n);
//     return 0;
// }

// Program 2
// #include <iostream>
// using namespace std;
// void fun(int* arr)
// {
//     int i;
//  //Consider the size of pointer as 8 bytes
//     unsigned int n = sizeof(arr) / sizeof(arr[0]); 
//     for (i = 0; i < n; i++)
//         cout << " " << arr[i];
// }

// // Driver program
// int main()
// {
//     int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
//     fun(arr);
//     return 0;
// }

// Program 4
// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// void fun(char* arr)
// {
//     int i;
//     unsigned int n = strlen(arr);
//     cout << "n = " << n << "\n";
//     for (i = 0; i < n; i++)
//         cout << " " << arr[i];
// }

// // Driver program
// int main()
// {
//     char arr[]
//         = { 'g', 'e', 'e', 'k', 's', 'q', 'u', 'i', 'z' };
//     fun(arr);
//     return 0;
// }

// Program 3
// #include <iostream>
// #include <string.h>
// using namespace std;
// void fun(char* arr)
// {
//     int i;
//     unsigned int n = strlen(arr);
//     cout << "n = " << n << endl;
//     for (i = 0; i < n; i++)
//         cout << arr[i] << " ";
// }

// // Driver program
// int main()
// {
//     char arr[] = "geeksquiz";
//     fun(arr);
//     return 0;
// }

// #include<stdio.h>
// int main()
// {
//   // arr[] is not terminated with '\0' 
//   // and its size is 5 
//   char arr[]= {'g', 'e', 'e', 'k', 's'}; 
  
//   printf("%lu", sizeof(arr));
//    return 0;
// }

#include<stdio.h>
int main()
{
  // size of arr[] is 6 as it is '\0' terminated 
  char arr[] = "geeks";
  
  printf("%lu", sizeof(arr));
  
  return 0;
}