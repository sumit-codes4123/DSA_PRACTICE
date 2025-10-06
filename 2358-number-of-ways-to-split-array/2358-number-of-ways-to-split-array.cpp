class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>presum(n);
        int cnt=0;
        presum[0]=nums[0];
        for(int i=1;i<n;i++){
            presum[i]=nums[i]+presum[i-1];
        }
        for(int i=0;i<n-1;i++){
            long long leftsum=presum[i];
           long long rightsum=presum[n-1]-presum[i];
            if(leftsum>=rightsum) cnt++;
        }return cnt;
    }
};