class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if (ranges::count(s, '1') < k) {
            return "";
        }

        int cnt = 0;
        string ans = s;
        for (int l = 0, r = 0; r < s.size(); r++) {
            cnt += s[r] - '0';
            while (cnt > k || s[l] == '0') {
                cnt -= s[l] - '0';
                l++;
            }
            if (cnt == k) {
                string t = s.substr(l, r - l + 1);
                if (t.length() < ans.length() ||
                    t.length() == ans.length() && t < ans) {
                    ans = move(t);
                }
            }
        }
        return ans;
    }
};