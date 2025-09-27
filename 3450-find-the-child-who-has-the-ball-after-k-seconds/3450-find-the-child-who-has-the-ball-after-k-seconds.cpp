class Solution {
public:
    int numberOfChild(int n, int k) {
  int ans = 0;
        bool a = true;
        for (int i = 0; i < k; i++) {
            if (a) {
                ans++;
                if (ans == n - 1) a = false;
            } else {
                ans--;
                if (ans == 0) a = true;
            }
        }
        return ans;
    }
};