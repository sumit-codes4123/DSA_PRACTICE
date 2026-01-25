class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int>res;
        res.reserve(nums.size());
        for(int x:nums) if(x>=0)res.push_back(x);
        if(res.empty()) return nums;
        k=k%res.size();
        rotate(res.begin(),res.begin()+k,res.end());
        int j=0;
        for(int &x:nums){
            if(x>=0) x=res[j++];
        }
        return nums;
    }
};