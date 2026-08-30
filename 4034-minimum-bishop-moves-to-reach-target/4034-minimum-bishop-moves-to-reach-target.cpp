class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
              int sr = source[0];
        int sc = source[1];

        int tr = target[0];
        int tc = target[1];
        if ((sr + sc) % 2 != (tr + tc) % 2) {
            return -1;
        }

        // Same diagonal
        if (abs(sr - tr) == abs(sc - tc)) {
            return 1;
        }

        // Same color, different diagonal
        return 2;
    }
};