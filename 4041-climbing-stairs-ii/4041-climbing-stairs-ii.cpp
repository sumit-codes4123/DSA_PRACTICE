class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
vector<int>a(n+1,1e9);
      a[0]=0;
        for(int k=0;k<n;k++){
            for(int l=1;l<=3;l++){
                if(k+l<=n)
                    a[k+l]=min(a[k+l],a[k]+costs[k+l-1]+l*l);
            }
        }return a[n];
    }
};