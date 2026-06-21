class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto edge:edges){
            int a=edge[0];
            int b=edge[1];
            int c=edge[2];
            adj[a].push_back({b,c});
        }
        vector<vector<int>>dist(n,vector<int>(k+1,1e9));
        priority_queue<pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>>pq;
        dist[0][1]=0;
        pq.push({0,{0,1}});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int d=curr.first;
            int u=curr.second.first;
            int cnt=curr.second.second;
            if(u==n-1)return d;
            if(d>dist[u][cnt])continue;
            for(auto & edge:adj[u]){
                int v=edge.first;
                int w=edge.second;
                int nc=(labels[u]==labels[v])?cnt+1:1;
                if(nc<=k){
                    if(d+w<dist[v][nc]){
                        dist[v][nc]=d+w;
                        pq.push({dist[v][nc],{v,nc}});
                    }
                }
            }
        }
        return -1;
    }
};