class Solution {
public:
    long long solve(int node,vector<vector<int>>&adj,vector<int>&arr){
        long long ans=arr[node];
        if(adj[node].size()==0)return ans;
        long long mini=LLONG_MAX;
        long long maxi=LLONG_MIN;
        for(auto adjnode:adj[node]){
            long long t=solve(adjnode,adj,arr);
            mini=min(mini,t);
            maxi=max(maxi,t);
        }
        return 2*maxi-mini+ans;
}
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        return solve(0,adj,baseTime);
    }
};