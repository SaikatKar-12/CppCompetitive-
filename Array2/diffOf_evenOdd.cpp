#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int odd_sum=0,even_sum=0;
    vector<int> v;
    int n;
    cout << "Enter array size:";
    cin >> n;
    cout << "Enter array elements:";
    for (int i = 0; i <= n - 1; i++)
    {
        int q;
        cin >> q;
        v.push_back(q);
    }
    for(int i = 0; i <= n - 1; i++){
        if(i%2==0) even_sum=even_sum+v[i];
        else odd_sum=odd_sum+v[i];
    }
    cout<<"Difference is "<<even_sum-odd_sum;
    return 0;
}