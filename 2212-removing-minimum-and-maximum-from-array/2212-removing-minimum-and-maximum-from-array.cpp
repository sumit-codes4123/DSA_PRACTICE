class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
         int n = nums.size();
        int a = INT_MAX, b = INT_MIN;
        int minIdx = 0, maxIdx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < a) {
                a = nums[i];
                minIdx = i;
            }
            if (nums[i] > b) {
                b = nums[i];
                maxIdx = i;
            }
        }
        int fromFront = max(minIdx, maxIdx) + 1;
        int fromBack = n - min(minIdx, maxIdx);
        int fromBoth = (minIdx + 1) + (n - maxIdx);
        int fromBoth2 = (maxIdx + 1) + (n - minIdx);
        return min({fromFront,fromBack,fromBoth,fromBoth2});
    }
};