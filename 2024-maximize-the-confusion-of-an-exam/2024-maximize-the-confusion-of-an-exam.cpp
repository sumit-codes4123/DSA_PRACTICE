class Solution {
public:
    int maxconsecutive(string &s,int k, char ch){
        int l=0,r=0,maxlen=0,n=s.size();
        int d=0;
        while(r<n){
            if(s[r]==ch)d++;
            if(d>k){
                if(s[l]==ch) d--;
                l++;
            }
            if(d<=k){
                maxlen=max(maxlen,r-l+1);
            }r++;
        }return maxlen;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
       return max(maxconsecutive(answerKey,k,'T'),maxconsecutive(answerKey,k,'F'));
    }
};