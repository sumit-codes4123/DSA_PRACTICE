class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
          sort(g.begin(), g.end()); // Sort greed factors
        sort(s.begin(), s.end()); // Sort cookie sizes
        int i = 0, j = 0; // i = child index, j = cookie index
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                // Cookie satisfies the child
                i++;
            }
            // Whether or not satisfied, move to next cookie
            j++;
        }
        return i;
    }
};