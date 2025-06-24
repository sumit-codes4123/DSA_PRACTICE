class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
      
        vector<int>temp;
        map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        for (auto& it : mpp) {
            if (it.second > n / 3) {
                temp.push_back(it.first);  
            }
        }
        return temp;     
    }
};