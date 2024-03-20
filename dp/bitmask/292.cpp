/*
[TAG]
bitmask
[URL]
https://www.acwing.com/problem/content/294/
https://www.acwing.com/solution/content/57859/
[INPUT]
10 5
PHHPP
HPPHP
PPHPP
PPPPP
PPPPP
PPHPP
PPHPP
HPPPH
HPHHH
HPHPH
[OUTPUT]
15
*/
#include <iostream>
#include <vector>
using namespace std;
const int N = 110, M = 1 << 10;
int n, m;
int g[N], cnt[M];
int f[2][M][M];
vector<int> state;
vector<int> head[M];
bool check(int st) {
    return !(st & st >> 1 || st & st >> 2);
}
int count(int st) {
    int res = 0;
    while (st) {
        res += st & 1;
        st >>= 1;
    }
    return res;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            g[i] += (c == 'H') << j;
        }
    }
    for (int st = 0; st < 1 << m; st++) {
        if (check(st)) {
            state.push_back(st);
            cnt[st] = count(st);
        }
    }
    for (int i = 0; i < state.size(); ++i) {
        for (int j = 0; j < state.size(); ++j) {
            if (!(state[i] & state[j])) {
                head[state[i]].push_back(state[j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int st : state) {
            if (!(g[i] & st)) {
                for (int p1 : head[st]) {
                    for (int p2 : head[p1]) {
                        if (!(st & p2)) { // 三层不能被攻击到
                            // 滚动数组，不开会爆空间
                            f[i & 1][st][p1] = max(f[i & 1][st][p1], f[(i - 1) & 1][p1][p2] + cnt[st]);
                        }
                    }
                }
            }
        }
    }
    int res = 0;
    for (int st : state) {
        for (int pre : head[st]) {
            res = max(res, f[n & 1][st][pre]);
        }
    }
    cout << res << endl;
}
int main() {
    solve();
    return 0;
}