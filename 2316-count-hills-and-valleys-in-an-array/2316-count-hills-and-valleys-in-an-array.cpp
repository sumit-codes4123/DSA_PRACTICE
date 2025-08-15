class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        for (int i = 1; i < n - 1; i++) {
            // Skip if current is equal to previous (still in a plateau)
            if (nums[i] == nums[i - 1]) continue;

            // Find previous different value
            int prev = i - 1;
            while (prev >= 0 && nums[prev] == nums[i]) prev--;

            // Find next different value
            int next = i + 1;
            while (next < n && nums[next] == nums[i]) next++;

            if (prev >= 0 && next < n) {
                if ((nums[i] > nums[prev] && nums[i] > nums[next]) ||
                    (nums[i] < nums[prev] && nums[i] < nums[next])) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
}; 