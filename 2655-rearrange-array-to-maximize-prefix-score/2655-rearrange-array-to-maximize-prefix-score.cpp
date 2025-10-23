class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long presum=0,ans=0;
        for(int i=n-1;i>=0;i--){
            presum+=nums[i];
            if(presum>0) ans++;
            else break;
        }return ans;
    }
};