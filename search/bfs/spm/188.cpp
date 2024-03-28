/*
[TAG]
SPM|BFS
[URL]
https://www.acwing.com/problem/content/190/
[INPUT]
10 11
..........
....*.....
..........
...*.*....
.......*..
..*..*...H
*.........
...*...*..
.K........
...*.....*
..*....*..
[OUTPUT]
5
*/

#include <iostream>
#include <cstring>

using namespace std;

#define x first
#define y second

typedef pair<int, int> pii;

const int N = 155, M = N * N;

int n, m;
char g[N][N];
pii q[M];
int dist[N][N];

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

int bfs() {

    int sx, sy;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'K') {
                sx = i, sy = j;
            }
        }
    }

    int hh = 0, tt = 0;
    q[0] = {sx, sy};

    memset(dist, -1, sizeof dist);
    dist[sx][sy] = 0;

    while (hh <= tt) {
        pii t = q[hh++];

        for (int i = 0; i < 8; ++i) {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 0 || b < 0 || a >= n || b >= m) continue;
            if (g[a][b] == '*') continue;
            if (dist[a][b] != -1) continue;
            if (g[a][b] == 'H') return dist[t.x][t.y] + 1;

            dist[a][b] = dist[t.x][t.y] + 1;
            q[++tt] = {a, b};
        }
    }

    return -1;

}

void solve() {

    cin >> m >> n;

    for (int i = 0; i < n; ++i) cin >> g[i];

    cout << bfs() << endl;

}

int main() {

    solve();

    return 0;
}