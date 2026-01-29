class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int maxlen=0;
        int csum=0;
        for(int i=0;i<nums.size();i++){
            csum+=(nums[i]==1)?1:-1;
            if(mpp.find(csum)!=mpp.end())maxlen=max(maxlen,i-mpp[csum]);
            else mpp[csum]=i;
        }return maxlen;
    }
};