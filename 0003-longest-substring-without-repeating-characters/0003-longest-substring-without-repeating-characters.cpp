class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256]={0};
        int n=s.size(),l=0,r=0,maxlen=0;
        if(n==1) return 1;
        for(int i=0;i<n;i++){
            hash[s[i]]++;
            while(hash[s[i]]>1){
                hash[s[l]]--;
                l++;
            }
            maxlen=max(maxlen,(i-l+1));
        }return maxlen;
    }
};