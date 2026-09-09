class Solution {
public:
    void solve(int col, int n, int & ans, vector<string>& b,
               vector<int>& l, vector<int>& ud, vector<int>& ld) {
        if (col == n) {
            ans++;
            return;
        }
        for (int row = 0; row < n; row++) {
            if (l[row] == 0 && ld[row + col] == 0 &&
                ud[n - 1 + col - row] == 0) {
                l[row] = 1;
                b[row][col] = 'Q';
                ld[row + col] = 1;
                ud[n - 1 + col - row] = 1;
                solve(col + 1, n, ans, b, l, ud, ld);
                b[row][col] = '.';
                l[row] = 0;
                ld[row + col] = 0;
                ud[n - 1 + col - row] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        int ans=0;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        vector<int> left(n, 0), ud(2 * n - 1, 0), ld(2 * n - 1, 0);
        solve(0, n, ans, board, left, ud, ld);
        return ans;
    }
};