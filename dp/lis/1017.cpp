/*
http://ybt.ssoier.cn:8088/problem_show.php?pid=1286

3
8
300 207 155 299 298 170 158 65
8
65 158 170 298 299 155 207 300
10
2 1 3 4 5 6 7 8 9 10

6
6
9
*/

#include <iostream>
#include <vector>

using namespace std;

const int N = 101;

void solve() {
    int n;
    cin >> n;
    vector<int> f(N), h(N);
    for (int i = 1; i <= n; ++i) 
        cin >> h[i];
    
    int ans = 0;   
    // 滑翔的方向是双向的
    for (int i = 1; i <= n; ++i) {
        f[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (h[i] > h[j])
                f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
    }

    for (int i = n; i >= 1; i--) {
        f[i] = 1;
        for (int j = n; j > i; j--) {
            if (h[i] > h[j])
                f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
    }

    cout << ans << endl;
}

int main() {

    int k;
    cin >> k;
    while (k--) {
        solve();
    }
    return 0;
}