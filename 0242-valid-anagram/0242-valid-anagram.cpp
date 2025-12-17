class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> res(26, 0);

        for (int i = 0; i < s.size(); i++) {
            res[s[i] - 'a']++;   // increment
            res[t[i] - 'a']--;   // decrement
        }

        for (int i = 0; i < 26; i++) {
            if (res[i] != 0)
                return false;
        }

        return true;
    }
};
