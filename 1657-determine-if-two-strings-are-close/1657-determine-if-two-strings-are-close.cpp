class Solution {
public:
    bool closeStrings(string w1, string w2) {
        int n=w1.size(),m=w2.size();
        if(n<m) return false;
        vector<int>f1(26,0),f2(26,0);
        for(int i=0;i<n;i++){
            f1[w1[i]-'a']+=1;
            f2[w2[i]-'a']+=1;
        }
        for(int i=0;i<26;i++){
            if((f1[i]!=0&&f2[i]==0)||(f1[i]==0&&f2[i]!=0)) return false;
        }
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        for(int i=0;i<26;i++){
            if(f1[i]!=f2[i]) return false;
        }return true;
    }
};