/*
[TAG]
01背包|二维变量
[URL]
https://www.acwing.com/problem/content/description/8/   
[INPUT]
4 5 6
1 2 3
2 4 4
3 4 5
4 5 6
[OUTPUT]
8
*/

#include <iostream>

using namespace std;

const int N = 101;
int f[N][N];

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    for (int i = 1; i <= n; ++i) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        for (int j = m1; j >= v1; j--) {
            for (int k = m2; k >= v2; k--) {
                f[j][k] = max(f[j][k], f[j - v1][k - v2] + w);
            }
        }
    }

    cout << f[m1][m2] << endl;
}

int main() {

    solve();

    return 0;
}