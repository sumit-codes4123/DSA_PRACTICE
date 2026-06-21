class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>>adj(n);
        queue<int>q;
        for(int i=0;i<p.size();i++){
            adj[p[i][1]].push_back(p[i][0]);
        }
        vector<int>id(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                id[it]++;
            }
        }
        for(int i=0;i<n;i++){
            if(id[i]==0)q.push({i});
        }
        vector<int>topo;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            topo.push_back(a);
            for(auto it:adj[a]){
                id[it]--;
                if(id[it]==0)q.push({it});
            }
        }
        if(topo.size()==n) return topo;
        return {};
    }
};