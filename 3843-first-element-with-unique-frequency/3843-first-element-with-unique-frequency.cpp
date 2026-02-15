class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>m1,m2;
        for(int x:nums) m1[x]++;
        for(auto &it:m1)m2[it.second]++;
        for(int it:nums) if(m2[m1[it]]==1)return it;
        return -1;
    }
};