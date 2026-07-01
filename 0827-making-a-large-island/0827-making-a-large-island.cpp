class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findUrPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUrPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu = findUrPar(u);
        int pv = findUrPar(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    bool isvalid(int i,int j,int n){
        return i>=0&&i<n&&j>=0&&j<n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DSU ds(n*n);
        int dr[4]={0,1,0,-1};
        int dc[4]={-1,0,1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j])continue;
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(isvalid(nr,nc,n)){
                        int node=n*i+j;
                        int adjnodeno=n*nr+nc;
                        if(ds.findUrPar(node)!=ds.findUrPar(adjnodeno)&&grid[nr][nc]){
                            ds.unionBySize(node,adjnodeno);
                        }
                    }
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                set<int>st;
                int x=1;
                if(!grid[i][j]){
                    for(int k=0;k<4;k++){
                        int nr=i+dr[k];
                        int nc=j+dc[k];
                        if(isvalid(nr,nc,n)&&grid[nr][nc]){
                            if(st.find(ds.findUrPar(n*nr+nc))==st.end()){
                                st.insert(ds.findUrPar(n*nr+nc));
                                x+=ds.size[ds.findUrPar(n*nr+nc)];
                            }
                        }
                    }mx=max(mx,x);
                }
            }
        }
        for(int i = 0; i < n * n; i++) {
            int row = i / n;
            int col = i % n;
            if(grid[row][col]) {
                mx = max(mx, ds.size[ds.findUrPar(i)]);
            }
        }
        return mx;
    }
};