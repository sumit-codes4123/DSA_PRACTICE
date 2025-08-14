class Solution {
public:
    int findMin(vector<int>& nums) {
       int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else if (nums[mid] < nums[high]) {
                high = mid;
            }
            else {
                // nums[mid] == nums[high] → can't determine; shrink range
                high--;
            }
        }
        return nums[low]; 
    }
};
