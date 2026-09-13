class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        stack<pair<int,int>>st;
        int n=nums.size();
        long long cnt=0;
        for(int i=0;i<n;i++){
            int ec=0;
            while(!st.empty()&&st.top().first>nums[i]){
                st.pop();
            }
            if(!st.empty()&&st.top().first==nums[i]){
                ec=st.top().second;
            }
            cnt+=(st.size()-ec);
            st.push({nums[i],ec+1});
        }
        return cnt;
    }
};