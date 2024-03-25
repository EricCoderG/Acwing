/*
[TAG]
interval|记忆化搜索
[URL]
https://www.acwing.com/problem/content/323/
https://www.acwing.com/solution/content/62836/
[INPUT]
3
1 1 1 1 1 1 1 3
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0
1 1 1 1 1 1 0 3
[OUTPUT]
1.633
*/

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 16;
int s[N][N];
double f[N][N][N][N][N];
double X;
int n, m = 8;

double get(int x1, int y1, int x2, int y2) {  //求该矩阵的 n\sigma^2
    double delta = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
    delta -= X;
    return delta * delta;
}

double dp(int k, int x1, int y1, int x2, int y2) {
    if (f[k][x1][y1][x2][y2] >= 0) return f[k][x1][y1][x2][y2];
    if (k == n) return f[k][x1][y1][x2][y2] = get(x1, y1, x2, y2);
    double t = 1e9; //初始化为无穷大
    for (int i = x1; i < x2; i ++ ) //横着切
    {
        t = min(t, dp(k + 1, x1, y1, i, y2) + get(i + 1, y1, x2, y2));
        t = min(t, dp(k + 1, i + 1, y1, x2, y2) + get(x1, y1, i, y2));
    }
    for (int i = y1; i < y2; i ++ ) //竖着切
    {
        t = min(t, dp(k + 1, x1, y1, x2, i) + get(x1, i + 1, x2, y2));
        t = min(t, dp(k + 1, x1, i + 1, x2, y2) + get(x1, y1, x2, i));
    }
    return f[k][x1][y1][x2][y2] = t;
}

void solve() {

    cin >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> s[i][j];
        }
    }
    // 预处理前缀和
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    
    memset(f, -1, sizeof f);
    X = (double) s[m][m] / n;
    printf("%.3lf\n", sqrt(dp(1, 1, 1, m, m) / n));
}

int main() {

    solve();

    return 0;
}