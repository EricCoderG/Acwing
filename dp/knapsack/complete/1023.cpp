/*
[TAG]
完全背包|计数
[URL]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1293
[INPUT]
20
[OUTPUT]
2
*/

#include <iostream>

using namespace std;

const int N = 1010;
int f[N];

void solve() {
    int n;
    cin >> n;
    f[0] = 1;
    int v[] = {10, 20, 50, 100};

    for (int i = 0; i < 4; ++i) {
        for (int j = v[i]; j <= n; j += 10) {
            f[j] += f[j - v[i]];

        }
    }

    cout << f[n] << endl;
}

int main() {

    solve();

    return 0;
}