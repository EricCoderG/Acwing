/*
[TAG]
SPM|BFS
[URL]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1255
[INPUT]
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
[OUTPUT]
(0, 0)
(1, 0)
(2, 0)
(2, 1)
(2, 2)
(2, 3)
(2, 4)
(3, 4)
(4, 4)
*/

#include <iostream>
#include <vector>

using namespace std;

using namespace std;

#define x first
#define y second

typedef pair<int, int> pii;

const int N = 7, M = N * N;

int n = 5;
int g[N][N];
pii q[M];
pii pre[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int sx, int sy) {

    int hh = 0, tt = 0;
    q[0] = {sx, sy};

    memset(pre, -1, sizeof pre);

    pre[sx][sy] = {0, 0};
    while (hh <= tt) {
        pii t = q[hh++];
        for (int i = 0; i < 4; ++i) {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 0 || b < 0 || a >= n || b >= n) continue;
            if (g[a][b]) continue;
            if (pre[a][b].x != -1) continue;

            q[++tt] = {a, b};
            pre[a][b] = t;
        }
    }
}

void solve() {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    bfs(n - 1, n - 1);

    pii end(0, 0);
    while (true) {
        printf("(%d, %d)\n", end.x, end.y);
        if (end.x == n - 1 && end.y == n - 1) break;
        end = pre[end.x][end.y];
    }
    
}

int main() {

    solve();

    return 0;
}