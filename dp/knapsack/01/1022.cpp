/*
[TAG]
01背包|二维变量|边界
[URL]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1292
[INPUT]
10 100 5
7 10
2 40
2 50
1 20
4 20
[OUTPUT]
3 30
*/

#include <iostream>

using namespace std;

const int N = 1010, M = 510;

int f[N][N];

void solve() {
    int m1, m2, n;
    // 注意 m2 != 0
    cin >> m1 >> m2 >> n;

    for (int i = 0; i < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;

        for (int j = m1; j >= v1; j--) {
            for (int k = m2; k >= v2; k--) {
                f[j][k] = max(f[j][k], f[j - v1][k - v2] + 1);
            }
        }
    }

    cout << f[m1][m2] << " ";

    int k = m2;

    while (k && f[m1][k - 1] == f[m1][m2]) k--;
    cout << m2 - k << endl;
}

int main() {

    solve();

    return 0;
}