class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f,vector<vector<int>>&s) {
        int m=f.size(),n=s.size();
        vector<vector<int>>ans;
        int i=0,j=0;
        while(i<m&&j<n){
            int s1=f[i][0];
            int s2=s[j][0];
            int e1=f[i][1];
            int e2=s[j][1];
            int start=max(s1,s2);
            int end=min(e1,e2);
            if(start<=end)ans.push_back({start,end});
            if(e1<e2)i++;
            else j++;
        }return ans;
    }
};