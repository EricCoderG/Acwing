/*
[TAG]
floyd
[URL]
https://www.acwing.com/problem/content/856/
https://www.acwing.com/solution/content/6976/
[INPUT]
3 3 2
1 2 1
2 3 2
1 3 1
2 1
1 3
[OUTPUT]
impossible
1
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 210, INF = 1e9;

int n, m;
int d[N][N];

void floyd() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }              
}

void solve() {

    int k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }

    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    floyd();
    while (k--) {
        int a, b;
        cin >> a >> b;
        if (d[a][b] > INF / 2) cout << "impossible" << endl;
        else cout << d[a][b] << endl;
    }
}

int main() {

    solve();

    return 0;
}