class Solution {
public:
       void solve(string current, int open, int close, int n, vector<string>& result) {
        if (open == n && close == n) {
            result.push_back(current);
            return;
        }
        if (open < n)
            solve(current + '(', open + 1, close, n, result);
        if (close < open)
            solve(current + ')', open, close + 1, n, result);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve("", 0, 0, n, result);
        return result; 
    }
};