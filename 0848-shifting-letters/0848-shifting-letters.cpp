class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.size();
        long long k=0;
        for(int i=n-1;i>=0;i--){
            k+=shifts[i];
            int x =((s[i]-'a')+k)%26;
            s[i]=(char)(x+'a');
        }return s;
    }
};