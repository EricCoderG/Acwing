/*
[TAG]
tree
[URL]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1575
[INPUT]
5 2
1 3 1
1 4 10
2 3 20
3 5 20
[OUTPUT]
21
*/

#include <iostream>

using namespace std;

const int N = 140, M = N << 1;

int n, m;
int h[N], e[M], ne[M], w[M], idx;
int f[N][N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u, int father) {

    for (int i = h[u]; i != -1; i = ne[i]) {
        if (e[i] == father) continue;
        dfs(e[i], u);
        for (int j = m; j >= 0; j--) {
            for (int k = 0; k < j; ++k) {
                f[u][j] = max(f[u][j], f[u][j - k - 1] + f[e[i]][k] + w[i]);
            }
        }
    }
}

void solve() {

    cin >> n >> m;
    memset(h ,-1, sizeof h);
    for (int i = 1; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    dfs(1, -1);

    cout << f[1][m] << endl;
}

int main() {

    solve();

    return 0;
}