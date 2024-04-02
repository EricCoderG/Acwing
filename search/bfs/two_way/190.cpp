/*
[TAG]
BFS|双向
[URL]
https://www.acwing.com/problem/content/description/192/
https://www.acwing.com/solution/content/41647/
[INPUT]
abcd xyz
abc xu
ud y
y yz
[OUTPUT]
3
*/

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

const int N = 6;

int n;
string a[N], b[N];

int extend(queue<string>& q, unordered_map<string, int>& da, unordered_map<string, int>& db, string a[], string b[]) {

    string t = q.front();
    q.pop();
    
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < n; ++j) {
            if (t.substr(i, a[j].size()) == a[j]) {
                string state = t.substr(0, i) + b[j] + t.substr(i + a[j].size());
                if (db.count(state)) return da[t] + 1 + db[state];
                if (da.count(state)) continue;
                da[state] = da[t] + 1;
                q.push(state);
            }
        }
    }

    return 11;
}

int bfs(string A, string B) {
    
    if (A == B) return 0;
    queue<string> qa, qb;
    unordered_map<string, int> da, db;

    // qa从起点开始搜，qb从终点开始搜
    qa.push(A), qb.push(B);  // 起点A到起点的距离为0
    da[A] = 0,  db[B] = 0;  // 终点B到终点B的距离为0

    while (qa.size() && qb.size()) {
        int t;
        if (qa.size() <= qb.size()) t = extend(qa, da, db, a, b);
        else t = extend(qb, db, da, b, a);

        if (t <= 10) return t;
    }
    return -1;
}

void solve() {

    string A, B;
    cin >> A >> B;
    while (cin >> a[n] >> b[n]) ++n;

    int t = bfs(A, B);
    if (t == -1) cout << "NO ANSWER!" << endl;
    else cout << t << endl;
}

int main() {

    solve();

    return 0;
}