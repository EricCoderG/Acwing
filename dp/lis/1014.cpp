/*
http://ybt.ssoier.cn:8088/problem_show.php?pid=1283

8
186 186 150 200 160 130 197 220

4
*/

#include <iostream>

using namespace std;

const int N = 1010;
int h[N], l[N], r[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    
    for (int i = 1; i <= n; ++i) {
        l[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (h[i] > h[j])
                l[i] = max(l[i], l[j] + 1);
        }
    }

    for (int i = n; i > 0; i--) {
        r[i] = 1;
        for (int j = n; j > i; --j) {
            if (h[i] > h[j])
                r[i] = max(r[i], r[j] + 1);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res = max(res, l[i] + r[i] - 1);
    }
    cout << res << endl;
    
}

int main() {

    solve();

    return 0;
}