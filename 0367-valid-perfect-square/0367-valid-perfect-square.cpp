class Solution {
public:
    bool isPerfectSquare(int num) {
                long l = 1;
        long r=num;
        while(l<=r){
            long mid = l+(r-l)/2;
            long sq = mid*mid;
            if(sq==num) return true;
            if(sq<num) l = mid+1;
            if(sq>num) r = mid-1;
        }
        return false;
    }
};