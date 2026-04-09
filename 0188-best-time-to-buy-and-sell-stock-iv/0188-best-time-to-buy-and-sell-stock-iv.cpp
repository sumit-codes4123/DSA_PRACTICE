class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int t = 2 * k - 1; t >= 0; t--) {
                if (t % 2 == 0) {
                    dp[i][t] = max(-prices[i] + dp[i + 1][t+1], 0 + dp[i + 1][t]);
                } else {
                    dp[i][t] = max(prices[i] + dp[i + 1][t+1], 0 + dp[i + 1][t]);
                }
            }
        }

        return dp[0][0];
    }
};