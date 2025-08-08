class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.size();
        
        for (int i = 0; i <= n - 3; i++) {
            // check if 3 consecutive chars are equal
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                string curr = num.substr(i, 3);
                if (curr > ans) {  // lex comparison works for digits
                    ans = curr;
                }
            }
        }
        
        return ans;

    }
};