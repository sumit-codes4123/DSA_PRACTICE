class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int prev = INT_MIN;
        for (int num : nums) {
            int l = max(num - k, prev + 1);
            int curr = min(l, num + k);
            if (curr > prev) {
                cnt++;
                prev = curr;
            }
        }
        return cnt;
    }
};