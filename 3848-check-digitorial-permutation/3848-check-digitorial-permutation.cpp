class Solution {
public:
    bool isDigitorialPermutation(int n) {
        int fact[10];
        fact[0]=1;
        for(int i=1;i<10;i++){
            fact[i]=fact[i-1]*i;
        }
        unordered_map<int,int>mpp;
        int x=n;
        int sum=0;
        while(x){
            int a=x%10;
            mpp[a]++;
            sum+=fact[a];
            x/=10;
        }
        while(sum){
            int a=sum%10;
            if(!mpp.count(a)) return false;
            mpp[a]--;
            if(mpp[a]==0) mpp.erase(a);
            sum/=10;
        }return mpp.empty();
    }
};