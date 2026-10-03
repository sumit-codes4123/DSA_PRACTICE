class Solution {
public:
    long long maxPoints(vector<vector<int>>& p) {
        int n = p.size();
        int m = p[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, -1));
        for (int i = 0; i < m; i++) {
            dp[0][i] = p[0][i];
        }
        for (int i = 1; i < n; i++) {
            vector<long long> lm(m, -1);
            vector<long long> rm(m, -1);
            lm[0] = dp[i - 1][0];
            for (int j = 1; j < m; j++) {
                lm[j] = max(lm[j- 1], dp[i - 1][j] + j);
            }
            rm[m - 1] = dp[i - 1][m - 1] - m + 1;
            for (int j = m - 2; j >= 0; j--) {
                rm[j] = max(rm[j + 1], dp[i - 1][j] - j);
            }
            for (int j = 0; j < m; j++) {
                dp[i][j] = max(lm[j] - j, rm[j] + j )+ p[i][j];
            }
        }
        long long cnt = -1;
        for (auto v : dp.back()) {
            cnt = max(cnt, v);
        }
        return cnt;
    }
};