class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, beams = 0;
        for (string s : bank) {
            int cnt = 0;
            for (char c : s) {
                if (c == '1')
                    cnt++;
            }
            if (cnt != 0) {
                beams += prev * cnt;
                prev = cnt;
            }
        }
        return beams;
    }
};