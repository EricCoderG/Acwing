/*
[TAG]
分组背包
[URL]
https://www.acwing.com/problem/content/9/
https://www.acwing.com/solution/content/3483/
[INPUT]
3 5
2
1 2
2 4
1
3 4
1
4 5
[OUTPUT]
8
*/

#include <iostream>

using namespace std;

const int N = 101;

int f[N];
int v[N][N], w[N][N], s[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        for (int j = 0; j < s[i]; ++j) {
            cin >> v[i][j] >> w[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 0; j--) {
            for (int k = 0; k < s[i]; k++) {
                if (j >= v[i][k]) {
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
                }
            }
        }
    }

    cout << f[m] << endl;
}

int main() {

    solve();

    return 0;
}