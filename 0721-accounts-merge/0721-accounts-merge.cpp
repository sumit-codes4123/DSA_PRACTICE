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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DSU ds(n);
        unordered_map<string,int>mmn;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mmn.find(mail)==mmn.end()){
                    mmn[mail]=i;
                }else{
                    ds.unionBySize(i,mmn[mail]);
                }
            }
        }
        vector<string >mm[n];
        for(auto it:mmn){
            string mail=it.first;
            int node=ds.findUpar(it.second);
            mm[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mm[i].size()==0)continue;
            sort(mm[i].begin(),mm[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mm[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};