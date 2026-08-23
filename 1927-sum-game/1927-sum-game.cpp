class Solution {
public:
    bool sumGame(string num) {
        int q1 = 0, q2 = 0;
        int n = num.size();
        int s1 = 0, s2 = 0;
        int j = n / 2;
        for (int i = 0; i < num.size() / 2; i++) {
            if (num[i] == '?')
                q1++;
            else s1 += (num[i]-'0');
            if (num[j] == '?')
                q2++;
            else s2 += (num[j]-'0');
            j++;
        }
        return ((q1 + q2) % 2 != 0) || (s1 - s2 != (q2 - q1) * 9 / 2);
    }
};