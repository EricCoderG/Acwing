/*
[TAG]
FLOOD FILL|BFS
[URL]
http://43.138.190.70:8888/p/AG0202
[INPUT]
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
[OUTPUT]
3
*/

#include <iostream>

using namespace std;

#define x first
#define y second

typedef pair<int, int> pii;

const int N = 110, M = N * N;

int n, m;
char g[N][N];
pii q[M];
bool st[N][N];

void bfs(int sx, int sy) {
    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    st[sx][sy] = true;

    while (hh <= tt) {
        pii t = q[hh++];

        for (int i = t.x - 1; i <= t.x + 1; ++i) {
            for (int j = t.y - 1; j <= t.y + 1; ++j) {
                if (i == t.x && j == t.y) continue;
                if (i < 0 || i >= n || j < 0 || j >= m) continue;
                if (g[i][j] == '.' || st[i][j]) continue;

                q[++tt] = {i, j};
                st[i][j] = true;
            }
        }
    }
}

void solve() {

    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> g[i];

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'W' && !st[i][j]) {
                bfs(i, j);
                ++cnt;
            }
        }
    }

    cout << cnt << endl;

}

int main() {

    solve();

    return 0;
}