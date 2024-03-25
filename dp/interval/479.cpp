/*
[TAG]
interval
[URL]
https://www.acwing.com/problem/content/481/
https://www.acwing.com/solution/content/3804/
[INPUT]
5
5 7 1 2 10
[OUTPUT]
145
3 1 2 4 5
*/

#include <iostream>

using namespace std;

const int N = 50;
int w[N];
int f[N][N];
int root[N][N];
int n;

void dfs(int l, int r) {

    if (l > r) return;
    int k = root[l][r];
    cout << k << " ";
    dfs(l, k - 1);
    dfs(k + 1, r);

}

void solve() {

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> w[i];

    for (int len = 1; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            for (int k = i; k <= j; ++k) {
                int l = k == i ? 1 : f[i][k - 1];
                int r = k == j ? 1 : f[k + 1][j];
                int score = l * r + w[k];
                if (i == j) score = w[k];
                if (score > f[i][j]) {
                    f[i][j] = score;
                    root[i][j] = k;
                }
            }
        }
    }

    cout << f[1][n] << endl;

    dfs(1, n);
}

int main() {

    solve();

    return 0;
}