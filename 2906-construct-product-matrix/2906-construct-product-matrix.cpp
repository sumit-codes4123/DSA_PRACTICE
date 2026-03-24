class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const int MOD = 12345;
        vector<vector<int>> mat(n, vector<int>(m));
        long long s = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                mat[i][j] = s;
                s = (s * grid[i][j]) % MOD;
            }
        }
        long long p = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = (p * mat[i][j]) % MOD;
                p = (p * grid[i][j]) % MOD;
            }
        }
        return mat;
    }
};