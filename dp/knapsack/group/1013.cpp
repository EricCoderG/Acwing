/*
[TAG]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1266
[URL]
分组背包|具体方案
[INPUT]
3 3    
30 40 50
20 30 50
20 25 30
[OUTPUT]
70                           
1 1  
2 1
3 1  
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 11, M = 16;
int w[N][M];
int f[N][M];
int way[N];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; j++) {
            cin >> w[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            //f[i][j] = f[i - 1][j]; 可以与下面的合并
            for (int k = 0; k <= j; k++) {
                f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);
            }
        }
    }

    cout << f[n][m] << endl;

    int j = m;
    for (int i = n; i > 0; i--) {
        for (int k = 0; k <= j; k++) {
            if (f[i][j] == f[i - 1][j - k] + w[i][k]) {
                way[i] = k;
                j -= k;
                break;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << i << ' ' << way[i] << endl;
    }

}

int main() {

    solve();

    return 0;
}