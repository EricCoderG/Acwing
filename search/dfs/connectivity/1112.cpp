/*
[TAG]
DFS|连通性模型
[URL]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1215
[INPUT]
2
3
.##
..#
#..
0 0 2 2
5
.....
###.#
..#..
###..
...#.
0 0 4 0
[OUTPUT]
YES
NO
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;
char g[N][N];
bool st[N][N];

int n;
int ax, ay, bx, by;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool dfs(int x, int y) {
    if (g[x][y] == '#') return false;

    if (x == bx && y == by) return true;
    st[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || b < 0 || a >= n || b >= n) continue;
        if (st[a][b]) continue;

        if (dfs(a, b)) return true;
    }
    return false;
}

void solve() {

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> g[i];
    cin >> ax >> ay >> bx >> by;
    memset(st, 0, sizeof st);

    if (dfs(ax, ay)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {

    int k;
    cin >> k;
    while (k--) solve();

    return 0;
}