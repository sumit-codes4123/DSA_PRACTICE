class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, int> st;
        long long ans = 0;
        string str = "";
        for(int i = 0; i < words.size(); i++)
        {
            int res = 0;
            for(int k = 0; k < 26; k++){
                str = "";
                for(int j = 0; j < words[i].size(); j++)
                    str += ((words[i][j] - 'a') + k)%26 + 'a';
                res += st[str];
            }
            ans += res;
            st[words[i]]++;
        }
        return ans;
    }
};