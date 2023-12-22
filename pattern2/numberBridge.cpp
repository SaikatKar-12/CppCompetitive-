#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter number:";
    cin >> n;
    m = n - 1;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        cout <<i;
    }
    cout << endl;
    for (int i = 1; i <= m; i++)
    {
        int a = 1;
        for (int j = 1; j <= m + 1 - i; j++)
        {
            cout << a;
            a++;
        }

        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << " ";
            a++;
        }
        for (int j = 1; j <= m + 1 - i; j++)
        {
            cout << a;
            a++;
        }
        cout << endl;
    }

    return 0;
}