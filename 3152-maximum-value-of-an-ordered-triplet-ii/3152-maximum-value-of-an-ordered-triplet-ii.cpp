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
        for (int i = 1; i < n - 1; i++) {
            long long left = leftMax[i - 1];
            long long right = rightMax[i + 1];
            long long val = (left - nums[i]) * right;
            ans = max(ans, val);
        }

        return ans;
    }
};
