/*
[TAG]
interval|大数乘法
[URL]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1571
[INPUT]
5
121 122 123 245 231
[OUTPUT]
12214884
*/

#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 55, M = 35, INF = 1e9;
int n;
int w[N];
ll f[N][N][M]; // M是位数   

void add(ll a[], ll b[]) {
    ll c[M];
    memset(c, 0, sizeof c);
    for (int i = 0, t = 0 ; i < M; ++i) {
        t += a[i] + b[i];
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a, c, sizeof c);
}

void mul(ll a[], ll b) {
    ll c[M];
    memset(c, 0, sizeof c);
    ll t = 0;
    for (int i = 0; i < M; ++i) {
        t += a[i] * b;
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a, c, sizeof c);
}

int cmp(ll a[], ll b[]) {

    for (int i = M - 1; i >= 0; i--) {
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    }
    return 0;
}

void print(ll a[]) {
    int k = M - 1;
    while (k && !a[k]) k--;
    while (k >= 0) cout << a[k--];
    cout << endl;
}

void solve() {

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> w[i];

    ll temp[M];
    for (int len = 3; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            f[i][j][M - 1] = 1;
            for (int k = i + 1; k < j; ++k) {
                memset(temp, 0, sizeof temp);
                temp[0] = w[i];
                mul(temp, w[k]);
                mul(temp, w[j]);
                add(temp, f[i][k]);
                add(temp, f[k][j]);
                if (cmp(f[i][j], temp) > 0) {
                    memcpy(f[i][j], temp, sizeof temp);
                }
            }
        }
    }

    print(f[1][n]);
}

int main() {

    solve();

    return 0;
}