class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        vector<long long >st;
        st.reserve(n);
        for(long long num:nums){
            while(!st.empty()&&num==st.back()){
                num+=st.back();
                st.pop_back();
            }st.push_back(num);
        }return st;
    }
};