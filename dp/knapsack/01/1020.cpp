/*
[TAG]
01背包|二维费用|边界|min
[URL]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1271
[INPUT]
5 60
5
3 36 120
10 25 129
5 50 250
1 45 130
4 20 119
[OUTPUT]
249
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 50, M = 160; // 两倍
int f[N][M];

void solve() {
    int m1, m2, n;
    cin >> m1 >> m2 >> n;

    memset(f, 0x3f, sizeof f); //正无穷
    f[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        for (int j = N - 1; j >= v1; j--) {
            for (int k = M - 1; k >= v2; k--) {
                f[j][k] = min(f[j][k], f[j - v1][k - v2] + w);
            }
        }
    }

    int res = 1e9;
    for (int i = m1; i < N; i++) {
        for (int j = m2; j < M; j++) {
            res = min(res, f[i][j]);
        }
    }

    cout << res << endl;

}

int main() {

    solve();

    return 0;
}