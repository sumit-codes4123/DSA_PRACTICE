class Solution {
public:
    int getLeastFrequentDigit(int n) {
        if(n==0) return 0;
        map<int, int> mpp;
        while (n >0) {
            mpp[n % 10]++;
            n /= 10;
        }
        int minFreq = INT_MAX;
        for (auto &it : mpp) {
            minFreq = min(minFreq, it.second);
        }
        int ans = 9;
        for (auto &it : mpp) {
            if (it.second == minFreq) ans = min(ans, it.first);
        }
        return ans;
    }
};