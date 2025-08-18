class Solution {
public:
int countSubarraysWithMaxSum(vector<int>& nums, int maxSum) {
        int count = 1;
        long long currentSum = 0;
        for (int num : nums) {
            if (currentSum + num <= maxSum) {
                currentSum += num;
            } else {
                count++;
                currentSum = num;
            }
        } return count;
    }
    int minimizeMaxSubarraySum(vector<int>& nums, int n, int k) {
        if (k > n) return -1;
        int low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int parts = countSubarraysWithMaxSum(nums, mid);
            if (parts > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return minimizeMaxSubarraySum(nums, nums.size(), k);
    }
};