class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        long long total = 0;
        int  target1 = skill[0] + skill[n - 1];
        for (int i = 0; i < n / 2; i++) {
            int target2 = skill[i] + skill[n - i - 1];
            if (target1 != target2)
                return -1;
            total += (long long)skill[i] * (long long)skill[n - i - 1];
        }
        return total;
    }
};