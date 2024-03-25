/*
[TAG]
interval|环形
[URL]
https://www.acwing.com/problem/content/322/
[INPUT]
4
2 3 5 10
[OUTPUT]
710
*/

#include <iostream>

using namespace std;

const int N = 210;
int w[N];
int f[N][N];
int s[N];
int n;

void solve() {

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        w[i + n] = w[i];
    }

    for (int len = 3; len <= n + 1; ++len) {
        for (int i = 1; i + len - 1 <= 2 * n; ++i) {
            int j = i + len - 1;
            for (int k = i + 1; k < j; ++k) {
                f[i][j] = max(f[i][j], f[i][k] + f[k][j] + w[i] * w[k] * w[j]);                
            }
        }
    }

    int res = 0;

    for (int i = 1; i <= n; ++i) {
        res = max(res, f[i][i + n]);
    }
    cout << res << endl;

}

int main() {

    solve();

    return 0;
}