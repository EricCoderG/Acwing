/*
[TAG]
FLOOD FILL|BFS
[URL]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1454
[INPUT]
5
8 8 8 7 7
7 7 8 8 7
7 7 7 7 7
7 8 8 7 8
7 8 8 8 8
[OUTPUT]
2 1
*/

#include <iostream>

using namespace std;

#define x first
#define y second

typedef pair<int, int> pii;

const int N = 1010, M = N * N;

int n;
int g[N][N];
pii q[M];
bool st[N][N];

void bfs(int sx, int sy, bool& has_higher, bool& has_lower) {
    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    st[sx][sy] = true;

    while (hh <= tt) {
        pii t = q[hh++];

        for (int i = t.x - 1; i <= t.x + 1; ++i) {
            for (int j = t.y - 1; j <= t.y + 1; ++j) {
                if (i == t.x && j == t.y) continue;
                if (i < 0 || j < 0 || i >= n || j >= n) continue;
                if (g[i][j] != g[t.x][t.y]) {
                    if (g[i][j] > g[t.x][t.y]) has_higher = true;
                    else has_lower = true;
                } else if (!st[i][j]) {
                    q[++tt] = {i, j};
                    st[i][j] = true;
                }
            }
        }
    }
}

void solve() {
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }

    int peak = 0, valley = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!st[i][j]) {
                bool has_higher = false, has_lower = false;
                bfs(i, j, has_higher, has_lower);
                if (!has_higher) peak++;
                if (!has_lower) valley++;
            }
        }
    }

    cout << peak << " " << valley << endl;

}

int main() {

    solve();

    return 0;
}