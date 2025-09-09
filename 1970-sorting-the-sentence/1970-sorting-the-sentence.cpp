class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        int cnt = 0, i = 0;
        string temp;
        while (i < s.size()) {
            if (s[i] == ' ') {
                int pos = temp[temp.size() - 1] - '0';
                temp.pop_back();
                ans[pos] = temp;
                temp.clear();
                cnt++;
                i++;
            } else {
                temp += s[i];
                i++;
            }
        }
        int pos = temp[temp.size() - 1] - '0';
        temp.pop_back();
        ans[pos] = temp;
        temp.clear();
        cnt++;
        for (int j = 1; j <= cnt; j++) {
            temp += ans[j];
            if (j < cnt) temp+= ' ';
        }
        return temp;
    }
};