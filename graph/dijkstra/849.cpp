/*
[TAG]
dijkstra
[URL]
https://www.acwing.com/problem/content/851/
https://www.acwing.com/solution/content/38318/
[INPUT]
3 3
1 2 2
2 3 1
1 3 4
[OUTPUT]
3
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 100010;

int h[N], e[M], ne[M], w[M], idx;
bool st[N];
int dist[N];
int n, m;

void add(int a, int b, int c) {
    w[idx] = c;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);

    dist[1] = 0;

    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 1; j <= n; ++j) {
            if (!st[j] && (t == -1 || dist[j] < dist[t])) {
                t = j;
            }
        }

        st[t] = true;

        for (int j = h[t]; j != -1; j = ne[j]) {
            int k = e[j];
            dist[k] = min(dist[k], dist[t] + w[j]);
        }
    }
}

void solve() {

    memset(h, -1, sizeof h);
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    dijkstra();

    if (dist[n] != 0x3f3f3f3f) {
        cout << dist[n] << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {

    solve();

    return 0;
}