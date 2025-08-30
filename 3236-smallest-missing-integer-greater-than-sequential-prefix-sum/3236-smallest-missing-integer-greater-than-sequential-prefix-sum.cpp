class Solution {
public:
    int missingInteger(vector<int>& nums) {
           unordered_set<int> s(nums.begin(), nums.end()); // O(n) lookups
        int sum = nums[0];
// Sum longest consecutive sequence starting from first element (original order)
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1)     sum += nums[i];
             else break;
        }// Increment until we find a missing number
        while (s.count(sum)) {
            sum++;
        }return sum;
    }
};