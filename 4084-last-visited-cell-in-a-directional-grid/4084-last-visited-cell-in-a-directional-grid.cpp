class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, true));
        vis[0][0] = false;
        int i = 0;
        int j = 0;
        while (true) {
            if (g[i][j] == 'R' && j + 1 < m && vis[i][j + 1]) {
                j = j + 1;
                vis[i][j] = false;
            } else if (g[i][j] == 'L' && j - 1 >= 0 && vis[i][j - 1]) {
                j = j - 1;
                vis[i][j] = false;
            } else if (g[i][j] == 'U' && i - 1 >= 0 && vis[i - 1][j]) {
                i = i - 1;
                vis[i][j] = false;
            } else if (g[i][j] == 'D' && i + 1 < n && vis[i + 1][j]) {
                i = i + 1;
                vis[i][j] = false;
            }
            else break;
        }
        return {i, j};
    }
};