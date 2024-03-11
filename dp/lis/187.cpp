/*
[TAG]
LIS|覆盖|暴搜
[URL]
https://www.acwing.com/problem/content/189/
[INPUT]
5
3 5 2 4 1
0 
[OUTPUT]
2
*/

#include <iostream>

using namespace std;

const int N = 55;
int h[N], up[N], down[N];
int n, ans;

void dfs(int u, int su, int sd) {
    if (su + sd >= ans) return;
    if (u == n) {
        ans = su + sd;
        return;
    }

    int k = 0, t;
    while (k < su && up[k] >= h[u]) k++;
    t = up[k];
    up[k] = h[u];
    if (k < su) dfs(u + 1, su, sd); // up[k] < h[u]
    else dfs(u + 1, su + 1, sd);  // k == su
    up[k] = t;

    k = 0;
    while (k < sd && down[k] <= h[u]) k++;
    t = down[k];
    down[k] = h[u];
    if (k < sd) dfs(u + 1, su, sd);
    else dfs(u + 1, su, sd + 1);
    down[k] = t;
}

void solve() {
    
    for (int i = 0; i < n; ++i) cin >> h[i];
    ans = n;
    dfs(0, 0, 0);
    cout << ans << endl;
}

int main() {

    while (cin >> n) {
        if (n) solve();
        else break;
    }

    return 0;
}