/*
[TAG]
dijkstra|堆
[URL]
https://www.acwing.com/problem/content/852/
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
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

const int N = 1e6 + 10;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dijkstra() {

    memset(dist, 0x3f, sizeof dist);

    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> heap;

    heap.push({0, 1});

    while (!heap.empty()) {
        pii t = heap.top();
        heap.pop();

        int cur = t.second;
        int dis = t.first;

        if (st[cur]) continue;
        st[cur] = true;

        for (int i = h[cur]; i != -1; i = ne[i]) {
            int k = e[i];
            if (dist[k] > dist[cur] + w[i]) {
                dist[k] = dist[cur] + w[i];
                heap.push({dist[k], k});
            }
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

    if (dist[n] != 0x3f3f3f3f) cout << dist[n] << endl;
    else cout << -1 << endl;
}

int main() {

    solve();

    return 0;
}