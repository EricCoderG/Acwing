/*
[TAG]
混合背包|二进制优化
[URL]
https://www.acwing.com/problem/content/description/7/
https://www.acwing.com/solution/content/23633/
[INPUT]
4 5
1 2 -1
2 4 1
3 4 0
4 5 2
[OUTPUT]
8
*/

#include <iostream>

using namespace std;

const int N = 100005;
int f[N], w[N], v[N];

void solve() {
    int n, m;
    cin >> n >> m;

    int cnt = 1;

    for (int i = 1; i <= n; ++i) {
        int a, b, s;
        cin >> a >> b >> s;
        if (s < 0) s = 1;
        else if (s == 0) s = m / b;

        int k = 1;
        while (k <= s) {
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
            ++cnt;
        }

        if (s > 0) {
            v[cnt] = a * s;
            w[cnt] = b * s;
            ++cnt;
        }
        
    }

    for (int i = 1; i <= cnt; ++i) {
            for (int j = m; j >= v[i]; j--) {
                f[j] = max(f[j], f[j - v[i]] + w[i]);
            }
        }

    cout << f[m] << endl;
}

int main() {

    solve();

    return 0;
}