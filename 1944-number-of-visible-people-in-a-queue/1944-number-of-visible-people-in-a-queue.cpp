class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int i=0,n=heights.size();
        vector<int>ans(n,0);
            stack<int>st;
        for(int i=n-1;i>=0;i--){
            int cnt=0;
            while(!st.empty()&&st.top()<heights[i]){
                st.pop();
                cnt++;
            }
            if(!st.empty()) cnt++;
            ans[i]=cnt;
            st.push(heights[i]);
        
        }return ans;
    }
};