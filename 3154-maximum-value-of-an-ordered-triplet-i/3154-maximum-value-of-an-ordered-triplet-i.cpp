class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i]);
        }
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }
        long long ans = 0;
        for (int j = 1; j < n - 1; j++) {
            long long val = (long long)(leftMax[j - 1] - nums[j]) * rightMax[j + 1];
            ans = max(ans, val);
        }
        return ans;
    }
};
