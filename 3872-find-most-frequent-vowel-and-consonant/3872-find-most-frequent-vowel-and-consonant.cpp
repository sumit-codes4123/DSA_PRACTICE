class Solution {
public:
    int maxFreqSum(string s) {
        if(s.empty()) return 0;
        map<char, int> mpp;
        map<char, int> mpp1;
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                mpp[c]++;
            else
                mpp1[c]++;
        }
        int maxFreq = 0;
        for (auto& p : mpp) {
            maxFreq = max(maxFreq, p.second);
        }
        int maxFreq1 = 0;
        for (auto& p : mpp1) {
            maxFreq1 = max(maxFreq1, p.second);
        }
        return maxFreq + maxFreq1;
    }
};