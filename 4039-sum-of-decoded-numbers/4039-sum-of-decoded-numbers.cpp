class Solution {
public:
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base = base % mod;
        while (exp > 0) {
            if (exp % 2 == 1) { 
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    int sumDecoded(vector<long long>& nums) {
        long long MOD = 1e9 + 7;
        long long sum = 0;

        for (long long num : nums) {
            int width = num % 10;
            long long d = num / 10;
            string s = to_string(d);

 
            string xs = s.substr(0, width);

            string ys = s.substr(width);
            long long x = stoll (xs);
            long long y = stoll(ys);

            long long curr = power(x, y, MOD);
            sum = (sum + curr) % MOD;
        }

        return sum;

    }
};