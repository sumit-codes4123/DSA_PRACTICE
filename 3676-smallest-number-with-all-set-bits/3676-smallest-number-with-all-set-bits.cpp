class Solution {
public:
    int smallestNumber(int n) {
        long long c = 1;
        while (c <= n) {
            c <<= 1; 
        }
        return c - 1;
    }
};
