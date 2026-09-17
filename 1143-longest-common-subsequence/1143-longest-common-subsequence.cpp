class Solution {
public:
    int solve(string& s1, string& s2, int i, int j,vector<vector<int>>&memo) {
        if (i == 0 || j == 0) 
            return 0;
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (s1[i-1] == s2[j-1]) {
            return memo[i][j] = 1 + solve(s1, s2, i -1, j - 1,memo);
        }
        return memo[i][j] = max(solve(s1, s2, i - 1, j,memo),solve(s1, s2, i, j - 1,memo));
    }
    int longestCommonSubsequence(string t1, string t2) {
        int n=t1.size();
        int m=t2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(t1, t2, n, m,dp);
    }
};
