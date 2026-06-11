class Solution {
public:
    string reverseWords(string s) {
        string result;
         int n = s.size();
        int j = -1;
        for (int i = 0; i < n; i++) {
            if ((i == n - 1) || s[i] == ' ') {
                int k = (i == n - 1) ? i : i - 1;
                for (; k > j; k--) {
                    result += s[k];
                }
                if (i != n - 1) {
                    result += ' ';
                }
                j = i;
            }
        }
        return result;
    }
};