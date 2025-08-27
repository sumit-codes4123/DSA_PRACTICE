class Solution {
public:
     bool digitsumeven(int n) {
        int k = n;
        int sum = 0;
        while (k != 0) {
            int digit = k % 10;
            sum += digit;
            k /= 10;
        }
        return (sum % 2 == 0);
    }
    int countEven(int num) {
        int cnt = 0;
        for (int i = 1; i <= num; i++) {
            if (digitsumeven(i))
                cnt++;
        }
        return cnt;
    }
};