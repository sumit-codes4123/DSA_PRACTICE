class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        long long maxi = LLONG_MIN, sum = 0;
        vector<long long> conver(n, 0);
        
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, (long long)nums[i]);
            conver[i] = sum + nums[i] + maxi;
            sum = conver[i];
        }
        return conver;
    }
};
