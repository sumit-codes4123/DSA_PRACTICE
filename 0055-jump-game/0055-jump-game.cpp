class Solution {
public:
    int solve(int i,int n,vector<int>&nums,vector<int>&memo){
        if(i>=n-1)return 1;
        if(nums[i]==0)return 0;
        if(memo[i]!=-1)return memo[i];
        for(int j=1;j<=nums[i];j++){
            if(solve(i+j,n,nums,memo))return memo[i]=1;
        }
        return memo[i]=0;
    }
    bool canJump(vector<int>& nums) {
        int max_ind=0;
        int n=nums.size();
        vector<int>memo(n+1,-1);
        return (solve(0,n,nums,memo)==1);

    }
};