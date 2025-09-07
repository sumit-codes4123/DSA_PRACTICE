class Solution {
public:
    int minOperations(string s) {
        vector<int>count(26,0);
       for(int i=0;i<s.size();i++){
        count[s[i]-'a']++;
       }
       for(int i=1;i<26;i++){      // wont include a
        if(count[i]!=0 ) return 26-i;
       }return 0;
    }
};