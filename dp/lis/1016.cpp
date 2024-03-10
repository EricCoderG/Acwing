/*
http://ybt.ssoier.cn:8088/problem_show.php?pid=1285

7
1 7 3 5 9 4 8

18
*/

#include <iostream>

using namespace std;

const int N = 1010;
int a[N], f[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];
    
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        f[i] = a[i];
        for (int j = 1; j < i; ++j) {
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + a[i]);
        }

        res = max(res, f[i]);
    }

    cout << res << endl;
}

int main() {

    solve();
    return 0;
}