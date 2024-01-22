#include<iostream>
#include<vector>
using namespace std;
vector<long long> countOfPairs(int n, int x, int y) {
        vector<long long> ans(n + 1);
        int X = x, Y = y;
        if (Y < X) {
            swap(X, Y);
        }
        if (X == Y) {
            // Normal
            for (int i = 1; i <= n; i++) {
                ans[i] += 1LL * 2 * (n - i);
            }
        } else {
            int c = Y - X + 1;
            // Within cycle
            for (int i = 1; i <= c / 2; i++) {
                ans[i] += 1LL * 2 * c;
                if (i == c / 2 && c % 2 == 0) {
                    ans[i] -= 1LL * c;
                }
            }
            // Left of cycle (inclusive of X)
            for (int i = 1; i < X; i++) {
                ans[i] += 1LL * 2 * (X - i);
            }
            // Right of cycle (inclusive of Y)
            for (int i = 1; i < n - Y + 1; i++) {
                ans[i] += 1LL * 2 * (n - Y + 1 - i);
            }
            vector<long long> mul(n + 2);
            // Cross the cycle (excluding X - Y)
            for (int i = 1; i < X; i++) {
                int d = X - i + 1;
                mul[d]++;
                mul[d + n - Y + 1]--;
            }
            mul[1 + 1]++;
            mul[1 + n - Y + 1]--;
            // Cycle to outsiders (excluding X and Y)
            for (int i = X + 1; i < Y; i++) {
                // Left
                if (X > 1) {
                    int d = min(Y - i + 1, i - X);
                    mul[d + 1]++;
                    mul[d + X]--;
                }
                // Right
                if (Y < n) {
                    int d = min(Y - i, i - X + 1);
                    mul[d + 1]++;
                    mul[d + n - Y + 1]--;
                }
            }
            for (int i = 1; i <= n; i++) {
                mul[i] += mul[i - 1];
                ans[i] += 2 * mul[i];
            }
        }
        return vector<long long>(ans.begin() + 1, ans.end());
    }
int main(){
    
    return 0;
}