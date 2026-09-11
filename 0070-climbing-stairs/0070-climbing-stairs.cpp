class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)return n;
        int p1=1;
        int p2=1;
        int r=0;
        for (int i = 2; i <= n; i++) {
            r=p1+p2;
            p1=p2;
            p2=r;
        }
        return r;
    }
};