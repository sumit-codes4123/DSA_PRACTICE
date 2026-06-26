class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,long long>>adj[n];
        priority_queue<pair<long long,int>,
            vector<pair<long long,int>>,
                greater<pair<long long,int>>>pq;
        int mod=1e9+7;
        vector<long long >dis(n,1e18);
        vector<int>ways(n,0);
        dis[0]=0;
        ways[0]=1;
        pq.push({0,0});
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        while(!pq.empty()){
            long long dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
             if(dist > dis[node]) continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                long long edw=it.second;
                if(dist+edw<(dis[adjnode])){
                    dis[adjnode]=(dist+edw);
                    pq.push({edw+dist,adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(dist+edw==dis[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};