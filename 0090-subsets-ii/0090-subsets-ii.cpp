class Solution {
public:
    void backtrack(int i,vector<int>&nums,vector<int>&ss,vector<vector<int>>&res){
        if(i==nums.size()){
            res.push_back(ss);
            return;
        }
        ss.push_back(nums[i]);
        backtrack(i+1,nums,ss,res);
        ss.pop_back();
        while(i+1<nums.size()&&nums[i]==nums[i+1]){
            i++;
        }
        backtrack(i+1,nums,ss,res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ss;
        sort(nums.begin(),nums.end());
        backtrack(0,nums,ss,res);
        return res;
    }

};