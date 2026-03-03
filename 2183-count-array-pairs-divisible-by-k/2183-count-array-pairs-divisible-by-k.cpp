class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        long long ans=0;
        for (int x : nums) {
            int g = gcd(x, k);
            for (auto &p : freq) {
                if ((long long)g * p.first % k == 0) ans += p.second;
            }
            freq[g]++;
        } return ans;
    }
};