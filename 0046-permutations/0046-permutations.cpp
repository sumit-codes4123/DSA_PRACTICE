class Solution {
public:

    void find(vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans,vector<bool>&freq){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i]=true;
                ds.push_back(nums[i]);
                find(nums,ds,ans,freq);
                freq[i]=false;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>freq(nums.size(),false);
        vector<vector<int>>ans;
        vector<int>ds;
        find(nums,ds,ans,freq);
        return ans;
    }
};