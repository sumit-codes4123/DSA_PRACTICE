class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long sum=0;
        for(int i=0;i<k;i++){
            long long curr=happiness[i]-i;
            if(curr>0) sum+=curr;
        }return sum;
    }
};