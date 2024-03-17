/*
[TAG]
有依赖的背包问题    
[URL]
https://www.acwing.com/problem/content/10/
https://www.acwing.com/solution/content/8316/
[INPUT]
5 7
2 3 -1
2 2 1
3 5 1
4 7 2
3 6 2
[OUTPUT]
11
*/

#include <iostream>
#include <vector>

using namespace std;

const int N = 110;
int f[N][N];

vector<int> g[N];
int v[N], w[N];
int n, m, root;

void dfs(int x) {
    
    for (int i = v[x]; i <= m; ++i) {
        f[x][i] = w[x]; //点x必须选，所以初始化f[x][v[x] ~ m]= w[x]
    }

    for (int i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        dfs(y);

        for (int j = m; j >= v[x]; j--) {  //j的范围为v[x]~m, 小于v[x]无法选择以x为子树的物品
            for (int k = 0; k <= j - v[x]; k++) {   //分给子树y的空间不能大于j-v[x],不然都无法选根物品x
                f[x][j] = max(f[x][j], f[x][j - k] + f[y][k]);
            }
        }
    }
}

void solve() {

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> v[i] >> w[i] >> p;
        if (p == -1) root = i;
        else g[p].push_back(i);
    }
    dfs(root);

    cout << f[root][m];
}

int main() {

    solve();

    return 0;
}