class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0,sindx=-1,m=t.size(),n=s.size(),cnt=0;
        int minlen=INT_MAX;
        int hash[256]={0};
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        while(r<n){
            if(hash[s[r]]>0) cnt++;
            hash[s[r]]--;
            while(cnt==m){
                if(r-l+1<minlen) {
                    minlen=r-l+1;
                    sindx=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }return sindx==-1?"":s.substr(sindx,minlen);
    }
};