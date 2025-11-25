class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        stack<int>st;
        for(int i=0;i<=heights.size();++i){
            while(!st.empty()&&(i==heights.size()||heights[st.top()]>heights[i])){
                int h=heights[st.top()];
                st.pop();
                int w=st.empty()?i:i-st.top()-1;
                ans=max(ans,h*w);
            }
            st.push(i);
        }return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()||matrix[0].empty()) return 0;
        int col=matrix[0].size();
        vector<int>heights(col,0);
        int maxi=0;
        for(auto & row:matrix){
            for(int i=0;i<col;i++)
               heights[i]=(row[i]=='1')?heights[i]+1:0;
            maxi=max(maxi,largestRectangleArea(heights));
        }return maxi;
    }
};