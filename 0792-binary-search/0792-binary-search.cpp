class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int f = 0, l = n - 1;
        while (f <= l) {
          int m = f + (l - f) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] < target)
                f = m + 1;
            else
                l = m - 1;
        }
        return -1;
    }
};