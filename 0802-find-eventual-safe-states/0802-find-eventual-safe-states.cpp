class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n=g.size();
        vector<int>ind(n,0);
        vector<int>adjRev[n];
        for(int i=0;i<n;i++){
            for(auto it:g[i]){
                adjRev[it].push_back(i);
                ind[i]++;
            }
        }
        queue<int>q;
        vector<int>safenode;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push({i});
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safenode.push_back(node);
            for(auto it:adjRev[node]){
                ind[it]--;
                if(ind[it]==0)q.push({it});
            }
        }
        sort(safenode.begin(),safenode.end());
        return safenode;
    }
};