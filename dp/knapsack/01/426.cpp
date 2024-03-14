/*
[TAG]
01背包
[URL]
https://www.acwing.com/problem/content/428/
[INPUT]
1000 5
800 2
400 5
300 5
400 3
200 2
[OUTPUT]
3900
*/

#include <iostream>

using namespace std;

const int N = 30010, M = 27;
int f[N];

void solve() {

    int n, m;
    cin >> m >> n;

    for (int i = 1; i <= n; ++i) {
        int v, p;
        cin >> v >> p;
        for (int j = m; j >= v; j--) {
            f[j] = max(f[j], f[j - v] + v * p);
        }
    }

    cout << f[m] << endl;
}

int main() {

    solve();

    return 0;
}