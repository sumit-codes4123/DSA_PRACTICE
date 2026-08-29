class Solution {
public:
    void backtrack(int i,int k,int t,vector<int>&res,vector<vector<int>>&ans){
        if(t==0&&k==0){
            ans.push_back(res);
            return ;
        }
        for(int j=i;j<=9;j++){
            if(j>t||k<=0)break;
            res.push_back(j);
            backtrack(j+1,k-1,t-j,res,ans);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>res;
        backtrack(1,k,n,res,ans);
        return ans;
    }
};