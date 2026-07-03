class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
        set<pair<int,int>>seen;
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            auto [max_d,r,c]=pq.top();
            pq.pop();
            if(seen.count({r,c}))continue;
            seen.insert({r,c});
            if(r==n-1&&c==m-1)return max_d;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&!seen.count({nr,nc})){
                    int new_d=max(max_d,grid[nr][nc]);
                    pq.push({new_d,nr,nc});
                }
            }
        }
        return -1;
    }
};