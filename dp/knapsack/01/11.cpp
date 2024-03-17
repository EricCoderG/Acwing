/*
[TAG]
01背包|方案数
[URL]
https://www.acwing.com/problem/content/description/11/
[INPUT]
4 5
1 2
2 4
3 4
4 6
[OUTPUT]
2
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n, m;
int f[N], g[N];

void solve() {
    cin >> n >> m;

    memset(f, -0x3f, sizeof f);
    f[0] = 0;
    g[0] = 1;

    for (int i = 1; i <= n; ++i) {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--) {
            int maxv = max(f[j], f[j - v] + w);
            int cnt = 0;
            if (maxv == f[j]) cnt += g[j];
            if (maxv == f[j - v] + w) cnt += g[j - v];
            g[j] = cnt % mod;
            f[j] = maxv; 
        }
    }

    int res = 0;
    for (int i = 0; i <= m; ++i) {
        res = max(res, f[i]);
    }

    int cnt = 0;
    for (int i = 0; i <= m; ++i) {
        if (res == f[i]) {
            cnt = (cnt + g[i]) % mod;
        }
    }

    cout << cnt << endl;
}

int main() {

    solve();

    return 0;
}