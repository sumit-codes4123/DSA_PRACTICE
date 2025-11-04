class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = 0;
        for (string c : sentences) {
            int cnt = 1;
            for (char s : c) {
                if (s == ' ')
                    cnt++;
            }
            maxi = max(cnt, maxi);
        }
        return maxi;
    }
};