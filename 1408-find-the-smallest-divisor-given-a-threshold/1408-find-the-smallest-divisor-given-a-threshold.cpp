class Solution {
public:
     int sumbyd(vector<int>& nums, int threshold) {
        int sum = 0;
        for(int num : nums) {
            sum += (num + threshold - 1) / threshold;  // Efficient ceiling calculation
        } return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(sumbyd(nums, mid) <= threshold) {
                high = mid - 1;  // Try to minimize divisor
            } else {
                low = mid + 1;  // Increase divisor
            }
        }return low;
    }
};