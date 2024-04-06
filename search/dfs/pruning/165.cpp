/*
[TAG]
DFS|剪枝
[URL]
https://www.acwing.com/problem/content/167/
https://www.acwing.com/solution/content/32118/
[INPUT]
5 1996
1
2
1994
12
29
[OUTPUT]
2
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 22;

int n, m, ans;
int cat[N], cab[N];

bool cmp(int a, int b) {return a > b;}

void dfs(int now, int cnt) { // 1 <= now <= n

    if (cnt >= ans) return;

    if (now == n + 1) {
        ans = min(ans, cnt);
        return;
    }

    for (int i = 1; i <= cnt; ++i) {
        if (cab[i] + cat[now] <= m) {
            cab[i] += cat[now];
            dfs(now + 1, cnt);
            cab[i] -= cat[now];
        }
    }

    cab[cnt + 1] = cat[now];
    dfs(now + 1, cnt + 1);
    cab[cnt + 1] = 0;


}

void solve() {

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> cat[i];

    sort(cat + 1, cat + n + 1, cmp);

    ans = n;
    dfs(1, 0);
    cout << ans << endl;
}

int main() {

    solve();

    return 0;
}