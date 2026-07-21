class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int cnt1=count(s.begin(),s.end(),'1');
        int i=0;
        int bestG=0;
        int prev=INT_MIN,cur=0;
        while(i<n){
            int st=i;
            while(i<n&&s[i]==s[st]){
                ++i;
            }
            if(s[st]=='0'){
                cur=i-st;
                bestG=max(bestG,prev+cur);
                prev=cur;
            }
        }
        return bestG+cnt1;      
    }
};