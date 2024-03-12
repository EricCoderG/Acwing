/*
[TAG]
01背包
[URL]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1295
[INPUT]
24
6
8
3
12
7
9
7
[OUTPUT]
0
*/

#include <iostream>

using namespace std;

const int N = 20010;
int f[N];

void solve() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        int v;
        cin >> v;
        for (int j = m; j >= v; j--) {
            f[j] = max(f[j], f[j - v] + v);
        }
    }

    cout << m - f[m] << endl; 

}

int main() {

    solve();

    return 0;
}