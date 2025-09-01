class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int i = n - 1;
        vector<int> result;

        // Process from last digit to first
        while (i >= 0 || k > 0) {
            if (i >= 0) {
                k += num[i]; // add digit to k
                i--;
            }
            result.push_back(k % 10); // current digit
            k /= 10; // carry
        }
        reverse(result.begin(), result.end());
        return result;
    }
};