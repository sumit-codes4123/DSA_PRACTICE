class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool zero=true;
        int xortotal = 0;
        for (int x : nums) {
            xortotal ^= x;
            if(x!=0)
            zero=false;
        }
        if(zero)return 0;
        if (xortotal!= 0)
            return n;
        return n > 1 ? n - 1 : 0;
    }
};