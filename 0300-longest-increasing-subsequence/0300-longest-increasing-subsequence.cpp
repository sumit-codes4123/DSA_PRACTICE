class Solution {
public:
    int solve(int i,int p,vector<int>&nums,vector<vector<int>>&dp){
        if(i==nums.size())return 0 ;
        if(dp[i][p+1]!=-1)return dp[i][p+1];
        int exclude=solve(i+1,p,nums,dp);

        int include=0;
        if(p==-1||nums[i]>nums[p]){
            include=1+solve(i+1,i,nums,dp);
        }
        return dp[i][p+1]= max(include,exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
         return solve(0,-1,nums,dp);
        
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         if(nums[i]>=nums[j]){
        //             dp[i][j]=1+dp[i-1][j-1];
        //         }
        //         else{
        //             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //         }
        //     }
        // }
        // return dp[0][0];
    }
};