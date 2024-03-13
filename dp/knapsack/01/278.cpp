/*
[TAG]
01背包|计数
[URL]w1
https://www.acwing.com/problem/content/280/
[INPUT]
4 4
1 1 2 2
[OUTPUT]
3
*/

#include <iostream>

using namespace std;

const int N = 10010;
int f[N];

void solve() {
    int n, m;
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int v;
        cin >> v;
        for (int j = m; j >= v; j--) {
            f[j] += f[j - v];
        }
    }

    cout << f[m] << endl;
}

int main() {

    solve();

    return 0;
}