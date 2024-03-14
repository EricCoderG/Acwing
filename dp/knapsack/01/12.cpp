/*
[TAG]
01背包|具体方案|字典序
[URL]
https://www.acwing.com/problem/content/description/12/
[INPUT]
4 5
1 2
2 4
3 4
4 6
[OUTPUT]
1 4
*/

#include <iostream>

using namespace std;

const int N = 1010;
int v[N], w[N];
int f[N][N];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];

    for (int i = n; i >= 1; --i) { // 满足字典序
        for (int j = 0; j <= m; ++j) {
            f[i][j] = f[i + 1][j];
            if (j >= v[i]) {
                f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
            }
        }
    }

    int j = m;
    for (int i = 1; i <= n; ++i) {
        if (j >= v[i] && f[i][j] == f[i + 1][j - v[i]] + w[i]) { //  说明选中了
            cout << i << ' ';
            j -= v[i];
        }
    }
}

int main() {

    solve();

    return 0;
}