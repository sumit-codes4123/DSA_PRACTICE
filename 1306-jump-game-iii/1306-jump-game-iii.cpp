class Solution {
public:
    bool solve(int i,int n,vector<int>&nums,vector<bool>&vis){
        if(i<0||i>=n||vis[i])return false;
        if(nums[i]==0)return true;
        vis[i]=true;
        return solve(i+nums[i],n,nums,vis)||solve(i-nums[i],n,nums,vis);
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool>vis(n,false);
        return solve(start,n,arr,vis);
    }
};