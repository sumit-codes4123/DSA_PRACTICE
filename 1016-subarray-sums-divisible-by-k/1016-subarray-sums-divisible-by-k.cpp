class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       unordered_map<int, int> mpp;
        mpp[0] = 1; 
        int presum = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i];
            int mod = (presum % k + k) % k; 
            if (mpp.find(mod) != mpp.end()) {
                count += mpp[mod];
            }
            mpp[mod]++;
        }

        return count; 
    }
};