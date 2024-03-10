/*
[TAG]
LIS|覆盖
[URL]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1260
[INPUT]
389 207 155 300 299 170 158 65
[OUTPUT]
6
2
*/

#include <iostream>

using namespace std;

const int N = 1010;
int h[N], f[N], g[N];

void solve() {
    int n = 0, ans = 0;
    while (cin >> h[n]) n++;
    for (int i = 0; i < n; ++i) {
        f[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (h[i] <= h[j])
                f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
    }
    cout << ans << endl;

    int cnt = 0; // 表示当前子序列的个数
    for (int i = 0; i < n; ++i) {
        int k = 0; // 序列下标
        while (k < cnt && g[k] < h[i]) ++k;
        g[k] = h[i];
        if (k >= cnt) ++cnt;
    }

    cout << cnt << endl;

}

int main() {

    solve();

    return 0;
}