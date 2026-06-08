class Solution {
public:
    bool canConstruct(string r, string m) {
        vector<int>a(26,0);
        for(int i=0;i<r.size();i++){
            a[r[i]-'a']++;
        }
        for(int i=0;i<m.size();i++){
            a[m[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(a[i]>=1)return false;
        }return true;
    }
};