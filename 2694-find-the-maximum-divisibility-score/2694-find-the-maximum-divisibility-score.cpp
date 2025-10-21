class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans=-1;
        int maxcnt=-1;
        for(int d:divisors){
            int cnt=0;
            for(int x:nums){
                if(x%d==0) cnt+=1;
            }if(cnt>maxcnt){
                maxcnt=cnt;
                ans=d;
            }
            else if(maxcnt==cnt)ans=min(ans,d);
        }return ans;
    }
};