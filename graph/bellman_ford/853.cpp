/*
[TAG]
bellman_ford
[URL]
https://www.acwing.com/problem/content/855/
https://www.acwing.com/solution/content/17551/
[INPUT]
3 3 1
1 2 1
2 3 1
1 3 3
[OUTPUT]
3
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int dist[N], backup[N];

int k, n, m;
typedef struct edge {
    int a;
    int b;
    int w;
} edge;

edge edges[N];

void bellman() {

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < k; ++i) {
        memcpy(backup, dist, sizeof dist);
        for (int j = 1; j <= m; ++j) {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
}

void solve() {

    cin >> n >> m >> k;

    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i].a = a, edges[i].b = b, edges[i].w = c;
    }

    bellman();
    if (dist[n] >= 0x3f3f3f3f / 2) cout << "impossible";
    else cout << dist[n];
}

int main() {

    solve();

    return 0;
}