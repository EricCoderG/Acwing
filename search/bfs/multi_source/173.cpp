/*
[TAG]
BFS|多源
[URL]
https://www.acwing.com/problem/content/175/
https://www.acwing.com/solution/content/40236/
[INPUT]
3 4
0001
0011
0110
[OUTPUT]
3 2 1 0
2 1 0 0
1 0 0 1
*/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

#define x first
#define y second

const int N = 1e3 + 10;
int n, m;
char g[N][N];
int dist[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs() {

    queue<pii> q;
    memset(dist, -1, sizeof dist);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '1') {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        pii t = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int sx = t.x + dx[i], sy = t.y + dy[i];
            if (sx < 0 || sy < 0 || sx >= n || sy >= m) continue;

            if (dist[sx][sy] == -1) {
                dist[sx][sy] = dist[t.x][t.y] + 1;
                q.push({sx, sy});
            }
        }
    }
}

void solve() {

    cin >> n >> m;

    for (int i = 0; i < n; ++i) cin >> g[i];

    bfs();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j > 0) cout << " ";
            cout << dist[i][j];
        }
        cout << endl;
    }
}

int main() {

    solve();

    return 0;
}