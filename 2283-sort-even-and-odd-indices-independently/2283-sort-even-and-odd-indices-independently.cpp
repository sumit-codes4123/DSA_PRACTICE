class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        for (int pass = 0; pass < n; pass++) {
            for (int i = 0; i + 2 < n; i += 2) {
                if (nums[i] > nums[i + 2]) {
                    swap(nums[i], nums[i + 2]);
                }
            }
        }
        for (int pass = 0; pass < n; pass++) {
            for (int i = 1; i + 2 < n; i += 2) {
                if (nums[i] < nums[i + 2]) {
                    swap(nums[i], nums[i + 2]);
                }
            }
        }
        return nums;
    }
};