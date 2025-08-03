class Solution {
public:
    int longestContinuousSubstring(string s) {
     int maxLen = 1, currLen = 1;    
        for (int i = 1; i < s.length(); i++) {
            if (s[i] - s[i - 1] == 1) {
                currLen++;
            } else {
                currLen = 1;
            }
            maxLen = max(maxLen, currLen);
        }
        return maxLen; 
    }
};