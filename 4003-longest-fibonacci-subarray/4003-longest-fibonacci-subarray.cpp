class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)return n;
        int ans=2,cnt=2;
        for(int i=2;i<n;i++){
            if(nums[i]==nums[i-1]+nums[i-2])cnt++;
            else cnt=2;
            ans=max(ans,cnt);
        }return ans;
    }
};