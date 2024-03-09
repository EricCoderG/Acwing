/*
https://www.acwing.com/problem/content/1017/

2
2 2
1 1
3 4
2 3
2 3 4
1 6 5

8
16
*/
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int m, n;
    cin >> m >> n;
    vector<vector<int> > w(m + 1, vector<int>(n + 1));
    vector<vector<int> > dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i) 
        for (int j = 1; j <= n; ++j) 
            cin >> w[i][j];
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = w[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[m][n] << endl;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}