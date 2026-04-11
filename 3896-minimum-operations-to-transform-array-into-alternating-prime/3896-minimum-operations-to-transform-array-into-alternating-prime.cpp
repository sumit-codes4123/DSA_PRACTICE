class Solution {
public:
    bool isprime(int n) {
        if(n<=1)return false;
        int k = sqrt(n);
        for (int i = 2; i <= k; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                if (!isprime(nums[i])) {
                    int v = nums[i];
                    while (!isprime(v)) {
                        v++;
                        cnt++;
                    }
                } else
                    continue;
            } else {
                if (isprime(nums[i])) {
                    int v = nums[i];
                    while (isprime(v)) {
                        v++;
                        cnt++;
                    }
                } else
                    continue;
            }
        }return cnt;
    }
};