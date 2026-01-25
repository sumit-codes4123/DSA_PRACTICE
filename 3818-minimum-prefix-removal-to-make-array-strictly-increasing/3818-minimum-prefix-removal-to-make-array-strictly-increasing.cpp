class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int i,n=nums.size();
        for(i=n-1;i-1>=0;i--){
            if(nums[i]<=nums[i-1])break;
            else continue;
        }return i;
    }
};