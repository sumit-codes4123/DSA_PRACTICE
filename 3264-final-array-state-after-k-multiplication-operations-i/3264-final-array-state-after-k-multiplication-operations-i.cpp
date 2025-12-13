class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k--) {
            int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();
            nums[minIndex] *= multiplier;
        }
        return nums;
    }
};