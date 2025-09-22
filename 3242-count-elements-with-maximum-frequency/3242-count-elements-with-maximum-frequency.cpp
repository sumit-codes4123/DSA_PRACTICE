class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mpp;
        int maxi=0;
        int sum=0;
        for(int c:nums){
            mpp[c]++;
            maxi=max(maxi,mpp[c]);
        }
        for(auto &it:mpp){
            if(it.second==maxi)   sum+=it.second;
        }return sum;
    }
};