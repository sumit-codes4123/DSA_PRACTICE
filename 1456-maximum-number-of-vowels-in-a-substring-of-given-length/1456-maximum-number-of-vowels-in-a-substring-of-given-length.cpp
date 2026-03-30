class Solution {
public:
    int maxVowels(string s, int K) {
        int n=s.size();
        int l=0,r=0;
        int maxi=0;
        string k="";
        int vowel=0;
        while(r<n){
            k+=s[r];
            char c=s[r];
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') vowel++;
            if(k.size()>K){
                char t=k[0];
                if(t=='a'||t=='e'||t=='i'||t=='o'||t=='u') vowel--;
                k.erase(0,1); 
            }
            maxi=max(maxi,vowel);
            r++;
        }
        return maxi;
    }
};