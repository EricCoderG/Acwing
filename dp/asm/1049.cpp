/*
[TAG]
asm
[URL]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1301
[INPUT]
2
3
1 8 2
4
10 7 6 14
[OUTPUT]
8
24
*/

#include <iostream>

using namespace std;

const int N = 100005, INF = 0x3f3f3f3f;

int w[N], f[N][2];

void solve() {
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> w[i];

    for (int i = 1; i <= n; ++i) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        f[i][1] = f[i - 1][0] + w[i];
    }

    cout << max(f[n][0], f[n][1]) << endl;
}

int main() {

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}