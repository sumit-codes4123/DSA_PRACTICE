class Solution {
public:
    long long minimumSteps(string s) {
        long long ones = 0;   // count of '1's encountered so far
        long long res = 0;    // total steps
        for (char c : s) {
            if (c == '1') {
                ones++;       // increase '1' count
            } else { // c == '0'
                res += ones;  // '0' must cross all previous '1's
            }
        }
        return res;
    }
};
