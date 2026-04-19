class Solution {
public:
    bool canTransform(string s, string r) {
        int n=s.size();
        int i=0,j=0;
        while(i<n||j<n){
            while(i<n&&s[i]=='X')i++;
            while(j<n&&r[j]=='X')j++;
            if(i==n||j==n)return i==j;
            if(s[i]!=r[j])return false;
            if(s[i]=='L'&&i<j)return false;
            if(s[i]=='R'&&i>j)return false;
            i++;
            j++;
        }return true;
    }
};