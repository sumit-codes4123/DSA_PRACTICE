class Solution {
public:
    bool isPalindrome(int x) {
        long long r, rev = 0,y=x;
        if(x<0)
        {return 0;}
        while (x > 0) {
            r = x % 10;
            rev = rev * 10 + r;
            x = x / 10;
        }
        if (rev == y) {
            return 1;
        } else {
            return 0;
        }
    }
};