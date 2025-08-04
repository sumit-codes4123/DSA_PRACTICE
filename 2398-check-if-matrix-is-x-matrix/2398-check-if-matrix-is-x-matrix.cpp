class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || i + j == n - 1) {
                    // Diagonal elements must be non-zero
                    if (grid[i][j] == 0)
                        return false;
                } else {
                    // Non-diagonal elements must be zero
                    if (grid[i][j] != 0)
                        return false;
                }
            }
        }
        return true;
    }
};