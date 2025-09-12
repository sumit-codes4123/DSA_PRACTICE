class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        int l= s.size();
        for (int rotatecnt = 0; rotatecnt < s.size(); ++rotatecnt) {
            rotate(s.begin(), s.begin() + 1, s.end());
            if (s == goal) return true;
        }
        return false;
    }
};