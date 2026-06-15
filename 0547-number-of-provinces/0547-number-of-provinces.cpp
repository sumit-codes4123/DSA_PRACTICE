class Solution {
public:
    void dfs(int node,vector<vector<int>>&ls,vector<int>&vis){
        vis[node]=1;
        for(auto it:ls[node]){
            if(!vis[it]){
                dfs(it,ls,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isC) {
        int n=isC.size();
        int m=isC[0].size();
        vector<vector<int>>ls(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isC[i][j]==1&&i!=j){
                    ls[i].push_back(j);  
                    ls[j].push_back(i);  
                }
            }
        }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,ls,vis);
            }

        }
        return cnt;
    }
};