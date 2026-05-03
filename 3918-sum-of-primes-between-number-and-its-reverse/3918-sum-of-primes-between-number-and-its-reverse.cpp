class Solution {
public:
    bool isprime(int num) {
        if (num <= 1)
            return false;
        if (num <= 3)
            return true;
        if (num % 2 == 0 || num % 3 == 0)
            return false;
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0)
                return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        int r = stoi(s);
        int j = min(n, r);
        int k = max(n, r);
        int sum = 0;
        for (int i = j; i <= k; i++) {
            if (isprime(i))
                sum += i;
        }
        return (int)sum;
    }
};