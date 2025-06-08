class Solution {
public:
    int reverse(int x) {
        int y=x ,rev=0,r;
        while (y!=0)
        {
            r=y%10;
             if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && r > 7))
                return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && r < -8))
                return 0;
            rev=rev*10+r;
            y=y/10;
        }
        return rev;

    }
};