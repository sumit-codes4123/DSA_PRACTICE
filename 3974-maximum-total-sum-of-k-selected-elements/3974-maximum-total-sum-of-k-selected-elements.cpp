class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),greater<>());
        long long tsum=0;
        for(int i=0;i<k;i++){
            long long ele=nums[i];
            if(mul>0)tsum+=(ele*mul);
            else tsum+=ele;
            mul--;
        }return tsum;
    }
};