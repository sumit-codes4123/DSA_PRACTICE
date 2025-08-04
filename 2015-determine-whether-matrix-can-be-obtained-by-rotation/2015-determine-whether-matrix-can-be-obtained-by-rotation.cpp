class Solution {
public:
    void rotate90(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& matrix,
                      vector<vector<int>>& target) {

        for (int i = 0; i < 4; i++) {
            if (matrix == target)   return true;
                rotate90(matrix);
        }
      return false;
    }
};

