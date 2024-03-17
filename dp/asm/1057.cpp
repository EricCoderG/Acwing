/*
[TAG]
asm
[URL]
https://www.acwing.com/problem/content/1059/
[INPUT]
3 2
2 4 1
[OUTPUT]
2
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010, M = 104;

int w[N], f[N][M][2];
// 注意一次买入卖出是合为一笔交易的

void solve() {

    int n, m;
    cin >> n >> m;

    memset(f, -0x3f, sizeof f);
    
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 0; i <= n; ++i) f[i][0][0] = 0;
    

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + w[i]);
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - w[i]);
        }
    }

    int res = 0;
    for (int i = 0; i <= m; ++i) res = max(res, f[n][i][0]);

    cout << res << endl;

}

int main() {

    solve();

    return 0;
}