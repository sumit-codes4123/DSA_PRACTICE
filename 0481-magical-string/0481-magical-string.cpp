class Solution {
public:
    int magicalString(int n) {
        int k = 2, c = 0;
        string s = "122";
        while (s.length() <= n) {
            int idx = s[k] - '0';
            for (int i = 1; i <= idx; i++) {
                if (k % 2 == 0)
                    s+='1';
                else
                    s+='2';
            }
            k++;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='1') c++;
        }return c;
    }
};