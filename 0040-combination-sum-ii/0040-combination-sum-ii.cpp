class Solution {
public:
    void solve(vector<int>&c,int t,vector<vector<int>>&ans,vector<int>comb,int j){
        if(t<0)return ;
        if(t==0)return ans.push_back(comb);
        for(int i=j;i<c.size();i++){
            if(i>j&&c[i]==c[i-1])continue;
            if(c[i]>t) break;
            comb.push_back(c[i]);
            solve(c,t-c[i],ans,comb,i+1);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        vector<vector<int>>ans;
        vector<int>comb;
        solve(c,t,ans,comb,0);
        return ans;
    }
};