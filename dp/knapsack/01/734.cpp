/*
[TAG]
01背包
[URL]
https://www.acwing.com/problem/content/description/736/
[INPUT]
3
4
20 10 1
5 30 5
100 30 1
5 80 60
3
10 4 1000
10 3 1000
10 8 1000
2
12 300 50
5 200 0
[OUTPUT]
Case #1: 105
Case #2: 8
Case #3: 500
*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10010;
int n;

struct stone {
    int s, e, l;
    bool operator< (const stone &x) const {
        return s * x.l < l * x.s; 
    } 
}stone[N];

int f[N];

void solve(int t) {
    int n;
    cin >> n;

    int m = 0;
    for (int i = 0; i < n; ++i) {
        int s, e, l;
        cin >> s >> e >> l;
        m += s;
        stone[i] = {s, e, l};
    }

    sort(stone, stone + n);

    memset(f, 0, sizeof f);
    for (int i = 0; i < n; ++i) {
        int s = stone[i].s, e = stone[i].e, l = stone[i].l;
        for (int j = m; j >= s; j--) {
            f[j] = max(f[j], f[j - s] + e - (j - s) * l);
        }
    }

    int res = 0;
    for (int i = 0; i <= m; ++i) res = max(res, f[i]);

    printf("Case #%d: %d\n", t, res);
}

int main() {

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) solve(i);

    return 0;
}