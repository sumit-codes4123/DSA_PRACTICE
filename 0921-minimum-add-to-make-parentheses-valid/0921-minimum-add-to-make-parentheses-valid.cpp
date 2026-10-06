class Solution {
public:
    int minAddToMakeValid(string s) {
        int o = 0, t = 0;
        for (char c : s) {
            if (c == '(')  o++;
            else  o > 0 ? o-- : t++;
        }return t + o;
    }
};