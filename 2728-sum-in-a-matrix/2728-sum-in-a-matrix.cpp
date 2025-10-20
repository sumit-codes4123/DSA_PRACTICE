class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int score = 0;
        int row = nums.size();
        int col = nums[0].size();
        for (int i = 0; i < row; i++) {
            sort(nums[i].begin(), nums[i].end());
        }
        for (int i = 0; i < col; i++) {
            int maxi = 0;
            for (int j = 0; j < row; j++) {
                if (nums[j][i] > maxi)
                    maxi = nums[j][i];
            }
            score += maxi;
        }
        return score;
    }
};