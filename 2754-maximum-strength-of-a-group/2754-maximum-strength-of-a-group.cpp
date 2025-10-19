class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return nums[0];
        long long product = 1;
        int negCount = 0, maxNeg = INT_MIN, nonZero = 0;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (x == 0) continue;
            if (x < 0) {
                maxNeg = max(maxNeg, x);
                ++negCount;
            }
            product *= x;
            ++nonZero;
        }
        if (nonZero == 0) return 0;
        if (negCount & 1) {
            if (nonZero == 1) return 0;
            product /= maxNeg;
        }
        return product;
    }
};

