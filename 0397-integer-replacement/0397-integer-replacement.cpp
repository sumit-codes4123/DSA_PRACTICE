class Solution {
public:
    unordered_map<long long, int> memo;
    int  solve(long long  n){
        if(n==1)return 0;
        if (memo.find(n) != memo.end()) return memo[n];
        if(n%2==0)return memo[n]=1+solve(n/2);
        else return memo[n]= 1+min(solve(n-1),solve(n+1));
    }
    int integerReplacement(int n) {
        return solve((long long)n);
        // return cnt;
    }
};