class Solution {
public:
    int cntsubarraywithkdistict(vector<int>& nums,int k){
        int cnt=0;
        unordered_map<int,int>mpp;
        int l=0,r=0;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l=l+1;
            }cnt+=(r-l+1);
            r=r+1;
        }return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      return (cntsubarraywithkdistict(nums,k)-cntsubarraywithkdistict(nums,k-1));
    }
};