/*
[TAG]
tree|只过了60%数据 O(n^2)
[URL]
https://www.acwing.com/problem/content/1075/
https://www.acwing.com/solution/content/65263/
[INPUT]
5 
2 1 1 
3 2 1 
4 3 1 
5 1 1
[OUTPUT]
2
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 10010, M = N << 1, INF = 0x3f3f3f3f;
int n;
int h[N], e[M], ne[M], w[M], idx;
int d1[N], d2[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dfs(int u, int father) {
    d1[u] = d2[u] = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        int dist = dfs(j, u) + w[i];
        if (dist >= d1[u]) {
            d2[u] = d1[u];
            d1[u] = dist;
        } else if (dist > d2[u]) {
            d2[u] = dist;
        }
    }
    return d1[u];
}

void solve() {

    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    int res = INF;
    for (int i = 1; i <= n; ++i) {
        res = min(res, dfs(i, -1));
    }
    cout << res << endl;
}

int main() {

    solve();

    return 0;
}