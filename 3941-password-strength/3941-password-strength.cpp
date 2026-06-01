class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> st(password.begin(), password.end());
        int ans = 0;
        for (auto it : st) {
            char c = it;
            if (c >= 97 && c <= 122)
                ans += 1;
            else if (c >= 65 && c <= 90)
                ans += 2;
            else if (isdigit(c))
                ans += 3;
            else
                ans += 5;
        }
        return ans;
    }
};