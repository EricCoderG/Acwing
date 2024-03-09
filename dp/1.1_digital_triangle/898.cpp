/*
https://www.luogu.com.cn/problem/P1216

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5 

30
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int> > v(n, vector<int>(n));
    vector<vector<int> > dp(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; ++i) dp[n - 1][i] = v[n - 1][i];
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = v[i][j] + max(dp[i + 1][j + 1], dp[i + 1][j]);
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}