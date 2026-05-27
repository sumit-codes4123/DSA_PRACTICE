class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastlow(26, -1), firstup(26, -1);
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (islower(c)) {
                lastlow[c - 'a'] = i;
            } else {
                if (firstup[c - 'A'] == -1) {
                    firstup[c - 'A'] = i;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lastlow[i] != -1 && firstup[i] != -1 && lastlow[i] < firstup[i])
                ans++;
        }
        return ans;
    }
};