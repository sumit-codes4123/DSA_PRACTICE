class Solution {
public:
    // int solve(int i,int n,vector<int>&nums,vector<int>&memo){
    //     if(i>=n-1)return 0;
    //     if (nums[i] == 0) return memo[i]=1e9; 
    //     if(memo[i]!=-1)return memo[i];
    //     int mini=1e9;
    //     for(int j=1;j<=nums[i];j++){
    //         int curr=solve(i+j,n,nums,memo);
    //         if(curr!=1e9){
    //             mini=min(mini,1+curr);
    //         }
    //     }
    //     return memo[i]=mini;
    // }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,1e9);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int mini=min(nums[i],n-i-1);
            int x=1e9;
            for(int j=1;j<=mini;j++){
                if(dp[i+j]!=1e9){
                    x=min(x,1+dp[i+j]);
                }
            }
            dp[i]=x;
        }
        return dp[0];
        
    }
};