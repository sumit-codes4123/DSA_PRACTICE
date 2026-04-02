class Solution {
public: 
    int solve(int i,int t,vector<int>&c,vector<vector<int>>&dp){
        if(i==0)return (t%c[0]==0);
        if(dp[i][t]!=-1)return dp[i][t];
        int not_take=solve(i-1,t,c,dp);
        int take=0;
        if(c[i]<=t) take=solve(i,t-c[i],c,dp);
        return dp[i][t]= not_take+take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
    }
};
// class Solution {
// public: RECURSION WITH TLE
//     int solve(int i,int t,vector<int>&c){
//         if(i==0)return (t%c[0]==0);
//         int not_take=solve(i-1,t,c);
//         int take=0;
//         if(c[i]<=t) take=solve(i,t-c[i],c);
//         return not_take+take;
//     }

//     int change(int amount, vector<int>& coins) {
//         int n=coins.size();
//          return solve(n-1,amount,coins);

//     }
// };