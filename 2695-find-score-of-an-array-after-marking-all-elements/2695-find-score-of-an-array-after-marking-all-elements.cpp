class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            int currentStart = i;
            while (i + 1 < nums.size() && nums[i + 1] < nums[i]) {
                i++;
            }
            for (int j = i; j >= currentStart; j -= 2) {
                ans += nums[j];
            }
        }
        return ans;
    }
};