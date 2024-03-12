/*
[TAG]
多重背包|二进制优化
[URL]
https://www.acwing.com/problem/content/5/
https://www.acwing.com/solution/content/5527/
[INPUT]
4 5
1 2 3
2 4 1
3 4 3
4 5 2
[OUTPUT]
10
*/

#include <iostream>
#include <vector>

using namespace std;

const int N = 2010;
typedef pair<int, int> pii;
int f[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> vv;

    for (int i = 1; i <= n; ++i) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int k = 1; k <= s; k *= 2) {
            s -= k;
            vv.emplace_back(k * w, k * v);
        }
        if (s) vv.emplace_back(s * w, s * v);
    }

    for (pii p : vv) {
        for (int j = m; j >= p.second; j--) {
            f[j] = max(f[j], f[j - p.second] + p.first);
        }
    }

    cout << f[m] << endl;
}

int main() {

    solve();

    return 0;
}