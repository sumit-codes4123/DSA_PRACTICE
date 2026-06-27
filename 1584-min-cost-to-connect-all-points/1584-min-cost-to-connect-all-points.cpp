class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int>vis(n,0);
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
                greater<pair<int,int>>>pq;
        pq.push({0,0});
        int sum=0;
        int ec=0;
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int wt=it.first;
            pq.pop();
            if(vis[node])continue;
            vis[node]=1;
            ec++;
            sum+=wt;
            if(ec==n)break;
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    int dis=abs(points[node][0]-points[i][0])+abs(points[node][1]-points[i][1]);
                    if(!vis[i]){
                        pq.push({dis,i});
                    }
                }
            }

        }   
        return sum;   


    }
};