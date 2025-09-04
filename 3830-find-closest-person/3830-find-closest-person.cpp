class Solution {
public:
    int findClosest(int x, int y, int z) {
      int d=abs(z-x) ,c=abs(z-y);
      if(d==c) return 0;
       return (d < c ? 1 : 2);
    }
};