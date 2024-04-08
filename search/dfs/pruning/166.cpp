/*
[TAG]
DFS|剪枝|优化
[URL]
https://www.acwing.com/problem/content/169/
https://www.acwing.com/solution/content/36030/
[INPUT]
9
5 2 1 5 2 1 5 2 1
4
1 2 3 4
0
[OUTPUT]
6
5
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 80;
int n;

int w[N];
bool st[N];

int sum, length;

//第u组,part第u组的已有长度,start表示第u组的枚举位置;
bool dfs(int u, int part, int start) {
    if (u * length == sum) return true;
    if (part == length) return dfs(u + 1, 0, 0);

    for (int i = start; i <= n; ++i) {
        if (st[i]) continue;
        if (w[i] + part > length) continue;
        st[i] = true;
        //因为前i个棍子都在第u组枚举了,所以直接从第i+1根棍子开始枚举
        if (dfs(u, w[i] + part, i + 1)) return true;
        st[i] = false;
        //如果第一根失败了或者最后一根失败了,就一定失败 -- 优化1
        // if(part == 0 || w[i] + part == length) return false;
        //如果i失败了,那么长度跟i一样的棍子也一定失败 -- 优化2
        int j = i;
        while(j <= n && w[j] == w[i]) j++;
        i = j - 1;
    }

    return false;
}

void solve() {
    
    memset(st, 0, sizeof st);

    sum = 0, length = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        sum += w[i];
    }

    sort(w + 1, w + n + 1);
    // 所有数都按照从大到小的顺序排列 -- 优化3
    reverse(w + 1, w + n + 1);

    while (1) {
        if (sum % length == 0 && dfs(0, 0, 0)) {
            cout << length << endl;
            break;
        }
        ++length;
    }
}

int main() {

    while (1) {
        cin >> n;
        if (n == 0) break;
        solve();
    }
    

    return 0;
}