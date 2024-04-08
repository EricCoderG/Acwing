/*
[TAG]
prim
[URL]
https://www.acwing.com/problem/content/860/
https://www.acwing.com/solution/content/38312/
[INPUT]
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
[OUTPUT]
6
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;
int g[N][N];
int dist[N];
bool st[N];
int pre[N];
int n, m;

void prim() {

    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    dist[1] = 0;

    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 1; j <= n; ++j) {
            if (!st[j] && (t == -1 || dist[j] < dist[t])) {
                t = j;
            }
        }

        if (dist[t] == 0x3f3f3f3f) {
            cout << "impossible" << endl;
            return;
        }

        st[t] = true;
        res += dist[t];

        for (int i = 1; i <= n; ++i) {
            if (dist[i] > g[t][i] && !st[i]) {
                dist[i] = g[t][i];
                pre[i] = t;
            }
        }
    }

    cout << res << endl;
}

void solve() {

    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b] = g[b][a] = min(g[a][b], w);
    }

    prim();
}

int main() {

    solve();

    return 0;
}