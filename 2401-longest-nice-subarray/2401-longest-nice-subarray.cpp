class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxlen=1;
        for(int i=0;i<nums.size()-maxlen;i++){
            int currlen=1;
            int x=nums[i];
            for(int j=i+1;j<nums.size();j++){
                if((x & nums[j])==0) {
                    x|=nums[j];
                    currlen++;
                }else break;
            }maxlen=max(maxlen,currlen);
        }return maxlen;
    }
};