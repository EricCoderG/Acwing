/*
[TAG]
01背包
[URL]
https://www.acwing.com/problem/content/2/
https://www.acwing.com/solution/content/1374/
[INPUT]
4 5
1 2
2 4
3 4
4 5
[OUTPUT]
8
*/

#include <iostream>

using namespace std;

const int N = 1010;
int f[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--) {
            f[j] = max(f[j - v] + w, f[j]);
        }
    }
    cout << f[m] << endl;
}

int main() {

    solve();

    return 0;
}