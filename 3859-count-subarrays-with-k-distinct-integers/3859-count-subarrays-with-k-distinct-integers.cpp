class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        unordered_map<int,int>mpp;
        int n=nums.size(),i=0,j=0,gcnt=0;
        long long cnt=0,prefix=0;
        while(j<n){
            mpp[nums[j]]++;
            if(mpp[nums[j]]==m)gcnt++;
            while(mpp.size()>k){
                if(mpp[nums[i]]==m)gcnt--;
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                i++;
                prefix=0;
            }
            while(mpp[nums[i]]>m){
                mpp[nums[i]]--;
                i++;
                prefix++;
            }
            if(mpp.size()==k&&gcnt==k)cnt+=prefix+1;
            j++;
        }return cnt;
    }
};