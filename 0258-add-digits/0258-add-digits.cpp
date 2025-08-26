class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;
            while (num != 0) {
                int digit = num % 10;  // Get last digit
                sum = sum + digit; // Append to reversed number
                num /= 10;         // Remove last digit
            }
            num = sum;
        }
        return num;
    }
};