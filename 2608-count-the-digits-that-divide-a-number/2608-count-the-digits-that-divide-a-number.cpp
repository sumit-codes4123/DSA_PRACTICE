class Solution {
public:
    int countDigits(int num) {
        int cnt = 0;
        int n = num;
        while (num != 0) {
            int digit = num % 10; // Get last digit
            if (digit != 0 && n % digit == 0)
                cnt++;
            num /= 10; // Remove last digit
        }return cnt;
    }
};