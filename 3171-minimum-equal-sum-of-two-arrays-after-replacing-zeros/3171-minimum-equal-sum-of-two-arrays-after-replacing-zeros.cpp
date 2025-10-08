class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long z1 = 0, z2 = 0;
        for (int x : nums1) {
            sum1 += x;
            if (x == 0) {
                sum1++;
                z1++;
            }
        }
        for (int x : nums2) {
            sum2 += x;
            if (x == 0) {
                sum2++;
                z2++;
            }
        }
        if (!z1 && sum2 > sum1 || !z2 && sum1 > sum2)
            return -1;
        return max(sum1, sum2);
    }
};