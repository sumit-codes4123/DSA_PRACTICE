class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
     int zerocnt = 0;
        for (int &x : nums) {
            x = (x % 2 == 0 ? 0 : 1);
            if (x == 0) zerocnt++;
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = (i < zerocnt ? 0 : 1);
        } return nums;
    }
};