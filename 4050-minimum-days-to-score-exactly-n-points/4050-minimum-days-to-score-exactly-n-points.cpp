class Solution {
public:
    vector<int>memo;
    int find(int n){
        if(n==0)return 0;
        if(memo[n]!=-1){
            return memo[n];
        }
        int d=INT_MAX;

        int k=1;

        while(1){
            int p=k*(k+1)/2;
            if(p>n)break;
            else if(p==n){
                d=min(d,k);
            }
            else{
                int rd=find(n-p);
                if(rd!=INT_MAX){
                    int td=k+1+rd;
                    d=min(d,td);
                }
            }
            k++;
        }
        return memo[n]=d;
    }
    int minDays(int n) {
        memo.assign(n+1,-1);
        return find(n);
    }
};