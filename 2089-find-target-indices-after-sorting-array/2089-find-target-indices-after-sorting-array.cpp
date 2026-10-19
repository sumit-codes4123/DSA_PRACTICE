class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        int cnt=0,c2=0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <target) {
                cnt++;
            }
            if(nums[i]==target)c2++;
        }
        while(c2){
            res.push_back(cnt++);
            c2--;
        }
        return res;
        
    }
};