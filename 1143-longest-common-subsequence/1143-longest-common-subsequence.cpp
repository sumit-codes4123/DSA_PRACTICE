class Solution {
public:
    int lcs(string &s1, string &s2, int m, int n) {
        if (m == 0 || n == 0) return 0;
        if (s1[m - 1] == s2[n - 1]) {
            return 1 + lcs(s1, s2, m - 1, n - 1);
        }
        return max(lcs(s1, s2, m, n - 1), lcs(s1, s2, m - 1, n));
    }
    int longestCommonSubsequence(string t1, string t2) {
        return lcs(t1, t2, t1.size(), t2.size());
    }
};
