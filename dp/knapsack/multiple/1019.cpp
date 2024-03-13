/*
[TAG]
多重背包
[URL]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1269
[INPUT]
5 1000
80 20 4
40 50 9
30 50 7
40 30 6
20 20 1
[OUTPUT]
1040
*/

#include <iostream>

using namespace std;

const int N = 6001;
int f[N];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        int v, w, s;
        cin >> v >> w >> s;
        while (s--) {
            for (int j = m; j >= v; j--) {
                f[j] = max(f[j], f[j - v] + w);
            }
        }
    }

    cout << f[m] << endl;
}

int main() {

    solve();

    return 0;
}