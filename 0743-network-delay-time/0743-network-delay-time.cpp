class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(n+1,1e9);
        dis[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto it=pq.top();
            int dist=it.first;
            int node=it.second;
            pq.pop();
            if(dist>dis[node]){
                continue;
            }
            for(auto &it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                if(dist+wt<dis[adjnode]){
                    dis[adjnode]=dist+wt;
                    pq.push({dist+wt,adjnode});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dis[i]==1e9)return -1;
            ans=max(ans,dis[i]);
        }
        return ans;
    }
};