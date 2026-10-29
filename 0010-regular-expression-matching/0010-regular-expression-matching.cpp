class Solution {
public:
    bool check(int i,int j,string &s, string &p) {
        if (j==p.size()) return i== s.size();
        
        bool match = (i<s.size() && (p[j] == s[i] || p[j] == '.'));
        
        if (j+1<p.size()&& p[j+1] == '*') {
            return (check(i,j+2,s,p)) || (match && check(i+1,j,s, p));
        } else {
            return match && check(i+1,j+1,s, p);
        }
    }
    
    bool isMatch(string s, string p) {
     
        return check(0,0,s, p);

    }
};
