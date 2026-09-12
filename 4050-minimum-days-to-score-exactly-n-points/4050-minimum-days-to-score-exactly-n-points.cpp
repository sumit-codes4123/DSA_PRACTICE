class Solution {
public:
    int minDays(int n) {
        long long curr=1;
        vector<int>dp(n+1,1e9+7);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(long long k=1;k*(k+1)/2<=i;k++){
                long long pt=k*(k+1)/2;
                if(pt==i){
                    dp[i]=k;
                }
                else{
                    dp[i]=min(dp[i],dp[i-pt]+(int)k+1);
                }
            }
        }
        return dp[n];
    }
};