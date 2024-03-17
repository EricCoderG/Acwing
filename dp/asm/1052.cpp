/*
[TAG]
asm
[URL]
https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/
[INPUT]
5
1 2 3 0 2
[OUTPUT]
3
*/

#include <iostream>

using namespace std;

int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n][3];
        memset(dp, 0, sizeof(dp));
        // dp[i][0]: 手上持有股票的最大收益
        // dp[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
        // dp[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }
        return max(dp[n - 1][1], dp[n - 1][2]);
    }

int main() {

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i - 1];
    }

    cout << maxProfit(v) << endl;

    return 0;
}