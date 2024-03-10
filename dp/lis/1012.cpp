/*
[TAG]
LIS
[URL]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1263
[INPUT]
7
22 4
2 6
10 3
15 12
9 8
17 17
4 2
[OUTPUT]
4
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;
typedef pair<int, int> pii;

pii q[N];
int f[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> q[i].first;
        cin >> q[i].second;
    }
    sort(q, q + n);
    int res = 0;

    for (int i = 0; i < n; ++i) {
        f[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (q[i].second > q[j].second) 
                f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }
    cout << res << endl;

}

int main() {

    solve();

    return 0;
}