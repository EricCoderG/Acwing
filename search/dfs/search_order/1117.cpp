/*
[TAG]
DFS|搜索顺序
[URL]
http://ybt.ssoier.cn:8088/problem_show.php?pid=1220
[INPUT]
5
at
touch
cheat
choose
tact
a
[OUTPUT]
23
*/

#include <iostream>

using namespace std;

const int N = 22;
string word[N];
int g[N][N];
int used[N];

int n, ans;

void dfs(string dragon, int last) {
    ans = max((int)dragon.size(), ans);

    used[last]++;

    for (int i = 0; i < n; ++i) {
        if (g[last][i] && used[i] < 2) {
            dfs(dragon + word[i].substr(g[last][i]), i);
        }
    }

    used[last]--;
}

void solve() {

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> word[i];
    char start;
    cin >> start;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            string a = word[i], b = word[j];
            for (int k = 1; k < min(a.size(), b.size()); ++k) {
                if (a.substr(a.size() - k, k) == b.substr(0, k)) {
                    g[i][j] = k;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (word[i][0] == start) {
            dfs(word[i], i);
        }
    }

    cout << ans << endl;
}

int main() {

    solve();

    return 0;
}