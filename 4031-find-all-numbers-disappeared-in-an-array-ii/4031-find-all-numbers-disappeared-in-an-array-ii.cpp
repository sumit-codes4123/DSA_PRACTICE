class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        int cur=lower;
        for(int num:nums){
            if(num<cur)continue;
            if(num>upper)break;
            if(num>cur){
                ans.push_back({cur,num-1});
            }
            cur=num+1;
        }
        if(cur<=upper){
            ans.push_back({cur,upper});
        }
        return ans;

    }
};