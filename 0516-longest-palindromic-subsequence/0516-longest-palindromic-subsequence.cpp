class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    dp[i][j] = (len == 2) ? 2 : 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
// class Solution {
// public:
//     int LPS(string s,int i,int j){  TLE SOLUTION RECURSION
//         if(i>j)return 0;
//         if(i==j) return 1;
//         if(s[i]==s[j])return 2+LPS(s,i+1,j-1);
//         else return max(LPS(s,i+1,j),LPS(s,i,j-1));
//     }
//     int longestPalindromeSubseq(string s) {
//         int i=0;
//         int j=s.size();
//         return LPS(s,i,j-1);
//     }
// };