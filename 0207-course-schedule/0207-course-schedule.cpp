class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pvis){
        vis[node]=1;
        pvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pvis)==true)return true;
            }
            else if(pvis[it]){
                return true;
            }
        }
        pvis[node]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>>adj(n);
        for(int i=0;i<p.size();i++){
            adj[p[i][0]].push_back(p[i][1]);
        }
        vector<int>vis(n,0);
        vector<int>pvis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pvis)==true)return false;
            }
        }
        return true;
    }
};