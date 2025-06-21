class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i=0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        while(  i < n -1) {
            if (nums[i] != nums[i+1]) {
                return nums[i];

            }else{
                i=i+2;
            }
        }
        return nums[n-1];
    }
};