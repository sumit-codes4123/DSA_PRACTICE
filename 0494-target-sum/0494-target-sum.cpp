class Solution {
public:
    int cnt=0;
    void count(vector<int>&nums,int i,int sum,int target){
        if(i==nums.size()){
            if(sum==target) cnt++;
        }
        else{
            count(nums,i+1,sum+nums[i],target);
            count(nums,i+1,sum-nums[i],target);
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        count(nums,0,0,target);
        return cnt;
    }
};