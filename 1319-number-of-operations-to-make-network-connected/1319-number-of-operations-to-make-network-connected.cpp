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
    int findUpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu = findUpar(u);
        int pv = findUpar(v);
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
    int makeConnected(int n, vector<vector<int>>& c) {
        int k = c.size();
        if(k<n-1)return -1;
        DSU ds(n);
        int ex=0;
        for(auto &edge:c){
            int u=edge[0];
            int v=edge[1];
            if(ds.findUpar(u)==ds.findUpar(v)){
                ex++;
            }
            else{
                ds.unionBySize(u,v);
            }

        }
        int com=0;
        for(int i=0;i<n;i++){
            if(ds.findUpar(i)==i)com++;
        }
        return (ex>=com-1)?com-1:-1;
    }
};