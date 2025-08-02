class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        long long i = num / 3;
        if (num % 3 == 0) {
            ans.push_back(i - 1);
            ans.push_back(i);
            ans.push_back(i + 1);
        }
        return ans;
    }
};