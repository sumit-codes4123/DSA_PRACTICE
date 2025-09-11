class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
            if (mpp[num] > 1) return true;
        } return false;
    }
};