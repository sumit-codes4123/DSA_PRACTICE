class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
         memset(hash, -1, sizeof(hash)); 
        int n=s.size(),l=0,r=0,maxlen=0;
        if(n==1) return 1;
        while(r<n){
            if(hash[s[r]]!=-1)
               if(hash[s[r]]>=l)
                  l=hash[s[r]]+1;
            int len=r-l+1;
            maxlen=max(maxlen,len);
            hash[s[r]]=r;
            r++;
        }return maxlen;
    }
};