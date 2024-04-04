/*
[TAG]
DFS|搜索顺序
[URL]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1219
[INPUT]
1
5 4 0 0
[OUTPUT]
32
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 10, M = 10;

int n, m, ans;
bool st[N][M];

int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

void dfs(int x, int y, int cnt) {

    if (cnt == n * m) {
        ++ans;
        return;
    }

    st[x][y] = true;

    for (int i = 0; i < 8; ++i) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || b < 0 || a >= n || b >= m) continue;
        if (st[a][b]) continue;

        dfs(a, b, cnt + 1);
    }

    st[x][y] = false;
}

void solve() {

    int x, y;
    cin >> n >> m >> x >> y;
    ans = 0;
    memset(st, 0, sizeof st);
    dfs(x, y, 1);

    cout << ans << endl;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}