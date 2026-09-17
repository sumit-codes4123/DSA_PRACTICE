class Solution {
public:
    int memo[1001][1001]; // DP matrix to store results

    int solve(string& s1, string& s2, int i, int j) {
        // Base case: if either string is fully processed
        if (i == s1.size() || j == s2.size()) {
            return 0;
        }

        // Return the cached result if already calculated
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        // Scenario 1: Characters match
        if (s1[i] == s2[j]) {
            return memo[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        }

        // Scenario 2: Characters do not match (explore both possibilities)
        int skip_s1 = solve(s1, s2, i + 1, j);
        int skip_s2 = solve(s1, s2, i, j + 1);

        return memo[i][j] = max(skip_s1, skip_s2);
    }

    int longestCommonSubsequence(string text1, string text2) {
        // Initialize memoization table with -1
        memset(memo, -1, sizeof(memo));
        return solve(text1, text2, 0, 0);
    }
};
