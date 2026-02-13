class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int i = 0, n = arr.size();
        if (n < 3)
            return 0;
        int ans = 0;
        while (i + 1 < n) {
            if (arr[i] < arr[i + 1]) {
                int j = i;
                int k = -1;
                while (i + 1 < n && arr[i + 1] > arr[i]) {
                    i++;
                }
                while (i + 1 < n && arr[i] > arr[i + 1]) {
                    i++;
                    k = i;
                }
                if (k != -1) {
                    ans = max(ans, i - j + 1);
                    i--;
                }
            }
            i++;
        }
        return ans;
    }
};