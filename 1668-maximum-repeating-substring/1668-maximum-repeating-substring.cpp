class Solution {
public:
    int maxRepeating(string s, string w) {
        int n=s.size();
        int m=w.size();
        int ans=0;
        vector<int>dp(n+1,0);
        for(int i=m;i<=n;i++){
            if(s.substr(i-m,m)==w){
                dp[i]=dp[i-m]+1;
                ans=max(ans,dp[i]);
            }
        }
        return ans;
    }
};