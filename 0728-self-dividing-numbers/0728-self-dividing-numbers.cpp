class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; i++) {
            int n = i;
            bool isSelfDividing = true;
            while (n > 0) {
                int digit = n % 10;
                if (digit == 0 || i % digit != 0) {
                    isSelfDividing = false;
                    break;
                }
                n /= 10;
            }
            if (isSelfDividing) result.push_back(i);
        }
        return result;
    }
};