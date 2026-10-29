class Solution {
public:
    bool check(int i,int j,string &s, string &p,vector <vector<int>>&memo) {
        if (j==p.size()) return i== s.size();
        if(memo[i][j]!=-1)return memo[i][j];
        bool match = (i<s.size() && (p[j] == s[i] || p[j] == '.'));
        
        if (j+1<p.size()&& p[j+1] == '*') {
            memo[i][j] =(check(i,j+2,s,p,memo)) || (match && check(i+1,j,s, p,memo));
        } else {
            memo[i][j]= match && check(i+1,j+1,s, p,memo);
        }
        return memo[i][j];
    }
    
    bool isMatch(string s, string p) {
        vector <vector<int>>m(s.size()+1,vector<int>(p.size()+1,-1));
        return check(0,0,s, p,m);

    }
};
