class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = 0;
        pq.push({0, {0, 0}});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if (r == n - 1 && c == m - 1)
                return diff;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int mineffort = max(abs(h[r][c] - h[nr][nc]), diff);
                    if (mineffort < dis[nr][nc]) {
                        dis[nr][nc] =mineffort;
                        pq.push({mineffort,{nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};