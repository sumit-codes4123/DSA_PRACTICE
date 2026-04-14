class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int prod=0;
        vector<int>dp(n);
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prod+=nums[i]*i;
        }
        dp[0]=prod;
        int maxi=dp[0];
        for(int i=1;i<n;i++){
               dp[i]=dp[i-1]+sum-n*nums[n-i];
               maxi=max(maxi,dp[i]);
        }return maxi;
    }
};