class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        if(n<2) return false;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int r=(k==0)?sum:sum%k;
            if(mpp.find(r)!=mpp.end()){
             if(i-mpp[r]>1) return true;
            }
            else mpp[r]=i;
        }return false;
    }
};