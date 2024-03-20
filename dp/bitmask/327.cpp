/*
[TAG]
bitmask
[URL]
https://www.acwing.com/problem/content/329/
[INPUT]
2 3
1 1 1
0 1 0
[OUTPUT]
9
*/

#include <iostream>
#include <vector>

using namespace std;

const int N = 14, M = 1 << 12, mod = 1e8;

int g[N];
vector<int> state;
vector<int> head[M];
int f[N][M];
int n, m; // row, col

bool check(int state) {
    for (int i = 0; i < m; ++i) {
        if ((state >> i & 1) && (state >> i + 1 & 1)) {
            return false;
        }
    }
    return true;
}

void solve() {

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            int t;
            cin >> t;
            g[i] += !t << j;
        }
    }

    for (int i = 0; i < 1 << m; ++i) {
        if (check(i)) state.push_back(i);
    }

    for (int i = 0; i < state.size(); ++i) {
        for (int j = 0; j < state.size(); ++j) {
            int a = state[i], b = state[j];
            if ((a & b) == 0) head[i].push_back(j);
        }
    }

    f[0][0] = 1;

    for (int i = 1; i <= n + 1; ++i) {
        for (int a = 0; a < state.size(); a++) {
            for (int b : head[a]) {
                if (g[i] & state[a]) continue; // 废弃的土地
                f[i][a] = (f[i][a] + f[i - 1][b]) % mod;
            }
        }
    }

    cout << f[n + 1][0] << endl;

}

int main() {

    solve();

    return 0;
}