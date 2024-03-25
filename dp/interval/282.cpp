/*
[TAG]
interval
[URL]
https://www.acwing.com/problem/content/description/284/
https://www.acwing.com/solution/content/13945/
[INPUT]
4
1 3 5 2
[OUTPUT]
22
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 310;
int f[N][N];
int a[N], s[N];
int n;

void solve() {

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
    }
    memset(f, 0x3f, sizeof f);

    for (int len = 1; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            if (len == 1) {
                f[i][j] = 0;
                continue;
            }

            for (int k = i; k <= j - 1; k++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }

    cout << f[1][n] << endl;
}

int main() {

    solve();

    return 0;
}