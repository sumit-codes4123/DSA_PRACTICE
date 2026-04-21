class Solution {
public:
    int minFlips(string target) {
        char s='0';
        int cnt=0;
        for(char c:target){
            if(c!=s){
                s=c;
                cnt++;
            }
        }
        return cnt;
    }
};