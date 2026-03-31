class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return grid[0][0];
        int firstMin = 0, secondMin = 0, firstIdx = -1;

        for (int i = 0; i < n; i++) {
            int curFirstMin = INT_MAX, curSecondMin = INT_MAX, curFirstIdx = -1;
            for (int j = 0; j < n; j++) {
                int prevBest = (j == firstIdx) ? secondMin : firstMin;
                int val = grid[i][j] + prevBest;
                if (val < curFirstMin) {
                    curSecondMin = curFirstMin;
                    curFirstMin = val;
                    curFirstIdx = j;
                } else if (val < curSecondMin) {
                    curSecondMin = val;
                }
            }
            firstMin = curFirstMin;
            secondMin = curSecondMin;
            firstIdx = curFirstIdx;
        } return firstMin;
    }
};