class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        long long sum=0;
        unsigned long long prod=1;
        for(int x:nums)sum+=x;
        for (int i = n-1; i>=0; i--) {
           sum-=nums[i];
           if(sum==prod)return i;
           if(prod>sum/nums[i])return -1;
           prod*=nums[i];
        }
        return -1;
    }
};