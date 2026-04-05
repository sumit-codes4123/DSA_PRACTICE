class Solution {
public:
    int memo[2001][2001];
    bool solve(int j, int i, string &s, string &p) {
        if (i < 0 && j < 0) return true;
        if (i < 0 && j >= 0) return false;
        if (j < 0 && i >= 0) {
            for (int ii = 0; ii <= i; ii++) {
                if (p[ii] != '*') return false;
            }
            return true;
        }
        if (memo[j][i] != -1) return memo[j][i];
        if (p[i] == s[j] || p[i] == '?') {
            return memo[j][i] = solve(j - 1, i - 1, s, p);
        }
        if (p[i] == '*') {
            return memo[j][i] = (solve(j, i - 1, s, p) || 
            solve(j - 1, i, s, p));
        } return memo[j][i] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                memo[i][j] = -1;
            }
        }return solve(n - 1, m - 1, s, p);
    }
};