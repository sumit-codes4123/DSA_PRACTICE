class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        long long mod=1e9+7;
        long long bestscore=-*min_element(nums.begin(),nums.end());
        int bestprime=2;
        set<int>prime;
        for(int num:nums){
            int x=num;
            for(int i=2;i*i<=x;i++){
                if(x%i==0){
                    prime.insert(i);
                    while(x%i==0)x/=i;
                }
            }
            if(x>1)prime.insert(x);
        }
        for(int p:prime){
            long long cur=0;
            long long maxi=LLONG_MIN;
            for(int num:nums){
                long long val=(num%p==0)?num:-num;
                cur=max(val,val+cur);
                maxi=max(maxi,cur);
            }
            if(maxi>bestscore){
                bestscore=maxi;
                bestprime=p;
            }else if(maxi==bestscore&&p<bestprime)bestprime=p;
        }
        bestscore=(bestscore%mod+mod)%mod;
        return (bestscore*bestprime)%mod;
    }
};