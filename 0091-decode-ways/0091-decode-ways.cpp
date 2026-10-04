class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')return 0;
        vector<int>dp(s.size()+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=s.size();i++){
            int o=s[i-1]-'0';
            int t=stoi(s.substr(i-2,2));
            if(o>=1&&o<=9){
                dp[i]+=dp[i-1];
            }
            if(t<=26&&t>=10){
                dp[i]+=dp[i-2];
            }
        }
        return dp[s.size()];
    }
};