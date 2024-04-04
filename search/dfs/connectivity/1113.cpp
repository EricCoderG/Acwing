/*
[TAG]
DFS|连通性模型
[URL]
https://www.acwing.com/problem/content/1115/
[INPUT]
6 9 
....#. 
.....# 
...... 
...... 
...... 
...... 
...... 
#@...# 
.#..#. 
0 0
[OUTPUT]
45
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 25;
char g[N][N];
bool st[N][N];

int n, m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs(int x, int y) {

    int cnt = 1;
    st[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || b < 0 || a >= n || b >= m) continue;
        if (st[a][b]) continue;
        if (g[a][b] != '.') continue;

        cnt += dfs(a, b);
    }

    return cnt;
}

void solve() {

    while (cin >> m >> n, n || m) {
        for (int i = 0; i < n; ++i) cin >> g[i];

        memset(st, 0, sizeof st);
        int x, y;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == '@') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        cout << dfs(x, y) << endl;
    }
}

int main() {

    solve();

    return 0;
}