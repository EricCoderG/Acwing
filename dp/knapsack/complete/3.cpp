/*
[TAG]
完全背包
[URL]
https://www.acwing.com/problem/content/3/
https://www.acwing.com/solution/content/5345/
[INPUT]
4 5
1 2
2 4
3 4
4 5
[OUTPUT]
10
*/

#include <iostream>

using namespace std;

const int N = 1010;
int v[N], w[N];
int f[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; ++i) {
        for (int j = v[i]; j <= m; ++j) {
            f[j] = max(f[j - v[i]] + w[i], f[j]);
        }
    }

    cout << f[m] << endl;
}

int main() {

    solve();

    return 0;
}