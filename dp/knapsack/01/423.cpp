/*
[TAG]
01背包
[URL]
https://www.acwing.com/problem/content/425/
[INPUT]
70 3
71 100
69 1
1 2
[OUTPUT]
3
*/

#include <iostream>

using namespace std;

const int N = 1010;
const int M = 101;
int f[N];

void solve() {
    int n, m;
    cin >> m >> n;

    for (int i = 1; i <= n; ++i) {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--) {
            f[j] = max(f[j], f[j - v] + w);
        }
    }

    cout << f[m] << endl;
}

int main() {

    solve();

    return 0;
}