/*
[TAG]
FLOOD FILL|BFS
[URL]
https://vjudge.net/problem/OpenJ_Bailian-2815
[INPUT]
4 
7 
11 6 11 6 3 10 6 
7 9 6 13 5 15 5 
1 10 12 7 13 7 5 
13 11 10 8 10 12 13
[OUTPUT]
5
9
*/

#include <iostream>

using namespace std;

#define x first
#define y second

typedef pair<int, int> pii;

const int N = 55, M = N * N;

int n, m;
int g[N][N];
pii q[M];
bool st[N][N];
// 西 北 东 南
int dx[] = {0, -1, 0, 1}; // 注意北是-1南是+1
int dy[] = {-1, 0, 1, 0};

int bfs(int sx, int sy) {
    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    st[sx][sy] = true;
    int area = 0;

    while (hh <= tt) {
        pii t = q[hh++];
        ++area;

        for (int i = 0; i < 4; ++i) {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (st[a][b]) continue;
            if (g[t.x][t.y] >> i & 1) continue;

            q[++tt] = {a, b};
            st[a][b] = true;
        }
    }

    return area;
}

void solve() {

    cin >> n >> m;

    int cnt = 0, area = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!st[i][j]) {
                area = max(area, bfs(i, j));
                ++cnt;
            }
        }
    }

    cout << cnt << endl;
    cout << area << endl;
}

int main() {

    solve();

    return 0;
}