class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long sum=0;
        long long mod=1e9+7;
        for(int x:nums)sum+=x;
        long long x=(sum+k-1)/k%mod;
        return (x-1)*x/2%mod ;
    }
};