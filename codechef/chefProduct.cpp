#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<pair<int, int>, int> dp;

int f(int n, int curr, int count) {
    if (n == 0) {
        return 1;
    }
    if (n < 0 || curr > n) {
        return 0;
    }
    if (dp.find({n, curr}) != dp.end()) {
        return dp[{n, curr}];
    }

    int includeCurr = f(n - curr, curr + 2, count + 1);
    int excludeCurr = f(n, curr + 2, count);

    return dp[{n, curr}] = includeCurr + excludeCurr;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        dp.clear();
        int n;
        cin >> n;
        int ans = f(n, 1, 0);
        cout << ans << endl;
    }

    return 0;
}

