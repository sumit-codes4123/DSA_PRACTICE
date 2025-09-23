class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int c1 = coordinate1[0] + (coordinate1[1] - '0');
        int c2 = coordinate2[0] + (coordinate2[1] - '0');
        return (c1 % 2) == (c2 % 2);
    }
};