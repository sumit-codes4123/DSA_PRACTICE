class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt=0;
        unordered_map<int,int>mpp;
        for(int i:nums) mpp[i]++;
        for(auto &[nums,f]:mpp){
            if(f==1)return -1;
            cnt+= (f + 2) / 3;
        }return cnt;
    }
};