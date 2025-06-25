class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mpp;
        int maxfreq = 0;
        int result = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                mpp[nums[i]]++;
            }
        }
        if (mpp.empty())
            return -1;

        for (auto& it : mpp) {
            if (it.second > maxfreq) {
                maxfreq = it.second;
                result = it.first;
            } else if (it.second == maxfreq && it.first < result) {
                result = it.first;
            }
        }
         return result;
    }
};

