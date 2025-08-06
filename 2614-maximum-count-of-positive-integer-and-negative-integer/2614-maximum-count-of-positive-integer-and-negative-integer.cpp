class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int c1 = 0, c2 = 0;
        for (int num : nums) {
            if (num < 0)
                c1++;
            else if (num > 0)
                c2++;
        }
        return max(c1, c2);
    }
};