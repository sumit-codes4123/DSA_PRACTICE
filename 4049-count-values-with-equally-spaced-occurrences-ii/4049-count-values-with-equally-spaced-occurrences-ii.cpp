class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int cnt=0;
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        for(auto &[num,it]:mpp){
            if(it.size()>=3){
                int d=it[1]-it[0];
                int c1=0;
                for(int i=1;i<it.size();i++){
                    if(it[i]-it[i-1]!=d)break;
                    c1++;
                }
                if(c1==it.size()-1)cnt++;
            }
        }
        return cnt;
    }
};