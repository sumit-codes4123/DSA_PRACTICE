class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxi = n;
        int i = 0;
        int j = 0;
        while (i < n) {
            while (j < n && nums[j] <= (long long)(nums[i]) * k) {
                j++;
            }
            maxi = min(maxi, n - (j - i));
            i++;
        }
        return maxi;
    }
};