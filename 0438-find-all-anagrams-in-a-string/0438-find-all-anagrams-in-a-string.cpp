class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int  n = s.size(), k = p.size();
        if(n<k) return ans;
        vector<int>freqp(26,0);
        vector<int>freqs(26,0);
        for(int i=0;i<p.size();i++){
            freqp[p[i]-'a']++;
            freqs[s[i]-'a']++;

        }
        for(int i=0;i<=n-k;i++) {
            if (freqp==freqs)
                ans.push_back(i);
            if (i<n-k) {
              freqs[s[i]-'a']--;
              freqs[s[i+k]-'a']++;
            }
        }return ans;
    }
};