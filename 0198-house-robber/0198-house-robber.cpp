class Solution {
public:
    int rob(vector<int>& nums) {
         int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev1 = 0; // dp[i - 1]
        int prev2 = 0; // dp[i - 2]

        for (int i = 0; i < n; i++) {
            int temp = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1=temp;
        }
        return prev1;
        
    }
};