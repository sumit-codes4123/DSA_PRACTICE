class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        int cnt=0;
        int l=0,i=0;
        int maxi=cnt;
        while(i<n&&l<n){
            if(mpp[nums[i]]<k){
                cnt++;
                mpp[nums[i]]++;
                maxi=max(maxi,cnt);
                i++;
            }else {
               mpp[nums[l]]--;
               cnt--;
               l++;
            }
        }
        return maxi;
    }
};