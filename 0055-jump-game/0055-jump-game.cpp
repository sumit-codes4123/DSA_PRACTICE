class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_ind=0;
        int n=nums.size();
        vector<bool>dp(n+1,false);
        dp[n-1]=true;
        for(int i=n-2;i>=0;i--){
            int maxi=min(nums[i],n-i-1);
            for(int j=1;j<=maxi;j++){
                if(dp[i+j]==true){
                    dp[i]=true;
                    break;
                }
            }
        }
    return dp[0];
    }
};