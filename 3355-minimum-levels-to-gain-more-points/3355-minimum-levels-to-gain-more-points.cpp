class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (possible[i] == 0)
                possible[i] = -1;
            sum += possible[i];
        }
        int sum2 = 0;
        for (int i = 0; i < n - 1; i++) {
            sum2 += possible[i];
            if (sum2 > sum - sum2)  return i + 1;
        } return -1;
    }
};