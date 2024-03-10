/*
[TAG]
二维DP
[URL]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1287
[INPUT]
5
1  4  6  8  10 
2  5  7  15 17 
6  8  9  18 20 
10 11 12 19 21 
20 23 25 29 33
[OUTPUT]
109
*/

#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > w(n + 1, vector<int>(n + 1));
    vector<vector<int> > dp(n + 1, vector<int>(n + 1));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> w[i][j];
        }
    }
    dp[1][1] = w[1][1];
    for (int i = 2; i <= n; ++i) {
        dp[i][1] = dp[i - 1][1] + w[i][1];
        dp[1][i] = dp[1][i - 1] + w[1][i];
    }
        
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            dp[i][j] = w[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[n][n] << endl;
}

int main() {

    solve();
    return 0;
}
/*
    与最大值不同，最小值需要考虑边界情况和特殊处理，可参考1015.cpp
*/