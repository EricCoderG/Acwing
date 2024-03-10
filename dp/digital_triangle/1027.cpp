/*
[TAG]
二维DP|走两次
[URL]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1277
[INPUT]
8
2 3 13
2 6 6
3 5 7
4 4 14
5 2 21
5 6 4
6 3 15
7 2 14
0 0 0
[OUTPUT]
67
*/

#include <iostream>
#include <vector>

using namespace std;

const int N = 15;
int w[N][N];
int dp[N * 2][N][N];

void solve() {
    int n;
    cin >> n;
    while (1) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0 && y == 0 && z == 0) break;
        w[x][y] = z;
    }

    for (int k = 2; k <= n * n; ++k) {
        for (int i1 = 1; i1 <= n; ++i1) {
            for (int i2 = 1; i2 <= n; ++i2) {
                int j1 = k - i1, j2 = k - i2;
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n) {
                    int t = w[i1][j1];
                    if (i1 != i2) t += w[i2][j2];
                    int &x = dp[k][i1][i2];
                    x = max(x, dp[k - 1][i1 - 1][i2 - 1] + t);
                    x = max(x, dp[k - 1][i1][i2 - 1] + t);
                    x = max(x, dp[k - 1][i1 - 1][i2] + t);
                    x = max(x, dp[k - 1][i1][i2] + t);
                }
            }
        }
    }

    cout << dp[n * 2][n][n];

}

int main() {

    solve();
    return 0;
}