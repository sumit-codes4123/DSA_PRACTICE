class Solution {
public:
    int maxIceCream(vector<int>& c, int coins) {
        vector<int>freq(100001);
        int n=c.size(),cnt=0;
        for(int x:c){
            freq[x]++;
        }
        for(int i=0;i<=100000;i++){
            if(freq[i]==0)continue;
            int canBuy=min(freq[i],coins/i);
            cnt+=canBuy;
            coins-=canBuy*i;
            if(coins<i)break;
        }return cnt;
    }
};