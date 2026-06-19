class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                queue<int> q;
                color[i] = 0;
                q.push(i);
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (auto it : g[node]) {
                        if (color[it] == -1) {
                            color[it] = !color[node];
                            q.push(it);
                        } else if (color[it] == color[node])
                            return false;
                    }
                }
            }
        }

        return true;
    }
};