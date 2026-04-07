class Solution {
public:
    int minimumDeletions(string s) {
        int B=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b')B++;
            else if(B>0){
                B--;
                ans++;
            }
        }
        return ans;
    }
};