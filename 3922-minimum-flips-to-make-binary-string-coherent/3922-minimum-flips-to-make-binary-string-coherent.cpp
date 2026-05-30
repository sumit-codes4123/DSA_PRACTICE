class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        if(n<3)return 0;
        int cnt0=count(s.begin(),s.end(),'0');
        int cnt1=n-cnt0;
        int res1=max(cnt1-1,0);
        int res2=cnt1-(s[0]-'0')-(s[n-1]-'0');
        return min({cnt0,res1,res2});
    }
};