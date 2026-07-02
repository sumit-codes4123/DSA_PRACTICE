class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        deque<pair<int,int>>dq;
        dist[0][0]=grid[0][0];
        dq.push_front({0,0});
       int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!dq.empty()){
            auto it=dq.front();
            int r=it.first;
            int c=it.second;
            dq.pop_front();
            if(r==n-1&&c==m-1)return dist[r][c]<health;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr<0||nr>=n||nc<0||nc>=m)continue;
                int w=grid[nr][nc];
                if(dist[r][c]+w<dist[nr][nc]){
                    dist[nr][nc]=dist[r][c]+w;
                    if(w==0){
                        dq.push_front({nr,nc});
                    }else{
                        dq.push_back({nr,nc});
                    }
                }
            }
        }
        return dist[n-1][m-1]<health;
    }
};