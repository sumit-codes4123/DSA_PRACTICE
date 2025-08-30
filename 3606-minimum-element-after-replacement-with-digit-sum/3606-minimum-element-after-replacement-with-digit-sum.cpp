class Solution {
public:
    int minElement(vector<int>& nums) {
        long long m = LLONG_MAX;
        for (int i = 0; i < nums.size(); i++) {
            long long n = nums[i];
            long long sum = 0;
            while (n > 0) {
                sum += (n % 10);
                n /= 10;
            }
            m = min(m, sum);
        }
        return (int)m;
    }
};