class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
                int r=0;
            while(x>0){
                r=r*10+x%10;
                x/=10;
            }st.insert(r);
        }return st.size();
    }
};