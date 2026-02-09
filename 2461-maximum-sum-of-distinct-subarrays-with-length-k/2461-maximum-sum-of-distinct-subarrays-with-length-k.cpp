class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0,csum=0;
        unordered_map<int,int>mpp;
        int begin=0,end=0,n=nums.size();
        while(end<n){
            int num=nums[end];
            int prev=mpp.count(num)?mpp[num]:-1;
            while(begin<=prev||end-begin+1>k){
                csum-=nums[begin];
                begin++;
            }
            mpp[num]=end;
            csum+=nums[end];
            if(end-begin+1==k)  ans=max(ans,csum);
            end++;
        }return ans;
    }
};