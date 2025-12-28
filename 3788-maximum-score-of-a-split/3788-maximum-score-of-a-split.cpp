class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n=nums.size(),min=nums[n-1];
        vector<int>suffixmin(n);
        int sum=0;
        for(int i=n-2;i>=0;i--){
            suffixmin[i]=min;
            min=fmin(min,nums[i]);
        }
        long long ans=nums[0]-suffixmin[0],prefixsum=0;
        for(int i=0;i<n-1;i++){
            prefixsum+=nums[i];
            ans=max(ans,prefixsum-suffixmin[i]);
        }return ans;
    }
};