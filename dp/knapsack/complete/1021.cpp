/*
[TAG]
完全背包|计数|long long
[URL]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1273
[INPUT]
3 10       
1          
2          
5         
[OUTPUT]
10
*/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {

    int n, m;
    cin >> n >> m;

    vector<ll> f(m + 1);
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        for (int j = x; j <= m; j++) {
            f[j] += f[j - x];
        }
    }

    cout << f[m] << endl;

}

int main() {

    solve();

    return 0;
}