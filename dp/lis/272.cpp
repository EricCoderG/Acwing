    /*
    [TAG]
    LIS|抽象出复杂的二维DP|等价替换降低循环次数
    [URL]
    https://www.acwing.com/problem/content/274/
    https://www.acwing.com/solution/content/4955/
    [INPUT]
    4
    2 2 1 3
    2 1 2 3
    [OUTPUT]
    2
    */

    #include <iostream>
    #include <algorithm>

    using namespace std;

    const int N = 3010;
    int a[N], b[N];
    int f[N][N];

    void solve() {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];

        for (int i = 1; i <= n; ++i) {
            int maxv = 1;
            for (int j = 1; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (a[i] == b[j]) f[i][j] = max(f[i][j], maxv);
                if (b[j] < a[i]) maxv = max(maxv, f[i - 1][j] + 1);
            }
        }
        
        int res = 0;
        for (int i = 1; i <= n; ++i) res = max(res, f[n][i]);

        cout << res << endl;


    }

    int main() {

        solve();

        return 0;
    }