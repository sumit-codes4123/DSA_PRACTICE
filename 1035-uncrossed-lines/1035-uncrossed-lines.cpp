class Solution {
public:
    int maxUncrossedLines(vector<int>& n1, vector<int>& n2) {
        int n=n1.size();
        int m=n2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(n1[i-1]==n2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max({dp[i][j-1],dp[i-1][j]});
                }
            }
        }return dp[n][m];
    }
};