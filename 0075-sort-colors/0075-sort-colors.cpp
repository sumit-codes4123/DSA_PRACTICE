class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c = nums.size();

        vector<int> temp;
        for (int n = 0; n <= 2; n++) {
            for (int i = 0; i < c; i++) {
                if (n == nums[i])
                    temp.push_back(nums[i]);
            }
        }
        for (int i = 0; i < c; i++) {
            nums[i] = temp[i];
        }
    }
};