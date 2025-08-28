class Solution {
public:
    bool hasEvenDigits(int num) {
        int digitCount = 0;
        while (num) {
            digitCount++;
            num /= 10;
        }
        return (digitCount & 1) == 0;
    }
    int findNumbers(vector<int>& nums) {
        int Count = 0;
        for (int num : nums) {
            if (hasEvenDigits(num)) Count++;
        }return Count;
    }
};