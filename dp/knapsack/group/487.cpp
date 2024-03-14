/*
[TAG]
分组背包|二进制优化
[URL]
https://www.acwing.com/problem/content/489/
https://www.acwing.com/solution/content/3803/
[INPUT]
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0
[OUTPUT]
2200
*/

#include <iostream>
#include <vector>

#define v first
#define w second

using namespace std;

typedef pair<int, int> pii;

const int N = 60, M = 32001; 

pii master[N];
vector<pii> servent[N];
int f[M];

void solve() {
    int n, m;
    cin >> m >> n;

    for (int i = 1; i <= n; ++i) {
        int v, p, q; 
        cin >> v >> p >> q;
        p *= v; 
        if (!q) master[i] = pii(v, p); 
        else servent[q].emplace_back(v, p); 
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 0; j--) {
            for (int k = 0; k < 1 << servent[i].size(); k++) {
                int v = master[i].v, w = master[i].w;
                for (int u = 0; u < servent[i].size(); u++) {
                    if (k >> u & 1) {
                        v += servent[i][u].v;
                        w += servent[i][u].w;
                    }
                }
                if (j >= v) {
                    f[j] = max(f[j], f[j - v] + w);
                }
            }
        }
    }  

    cout << f[m] << endl;
}

int main() {
    solve();
    return 0;
}

