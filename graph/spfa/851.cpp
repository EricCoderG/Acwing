/*
[TAG]
spfa
[URL]
https://www.acwing.com/problem/content/853/
https://www.acwing.com/solution/content/105508/
[INPUT]

[OUTPUT]

*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], w[N], ne[N], idx;
bool st[N];
int dist[N];
int q[N], hh, tt;
int n, m;

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void spfa() {

    q[0] = 1;
    dist[1] = 0;
    st[1] = true;

    while (tt >= hh) {
        int a = q[hh++];
        st[a] = false;
        for (int i = h[a]; i != -1; i = ne[i]) {
            int b = e[i], c = w[i];
            if (dist[b] > dist[a] + c) {
                dist[b] = dist[a] + c;
                if (!st[b]) {
                    q[++tt] = b;
                    st[b] = true;
                }
            }
        }
    }
}

void solve() {

    memset(h, -1, sizeof h);
    memset(dist, 0x3f, sizeof dist);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    spfa();

    if (dist[n] == 0x3f3f3f3f) cout << "impossible";
    else cout << dist[n];
}

int main() {

    solve();

    return 0;
}