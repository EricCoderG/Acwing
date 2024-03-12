/*
[TAG]
多重背包|01背包转化
[URL]
https://www.acwing.com/problem/content/4/
https://www.acwing.com/solution/content/13873/
[INPUT]
4 5
1 2 3
2 4 1
3 4 3
4 5 2
[OUTPUT]
10
*/

#include <iostream>

using namespace std;

const int N = 10010;
int f[N];

void solve() {
    int t, m;
    cin >> t >> m;
    while (t--) {
        int v, w, n;
        cin >> v >> w >> n;
        while (n--) {
            // 套01背包的板子
            for (int j = m; j >= v; j--) {
                f[j] = max(f[j], f[j - v] + w);
            }
        }
    }

    cout << f[m] << endl;
}

int main() {

    solve();

    return 0;
}