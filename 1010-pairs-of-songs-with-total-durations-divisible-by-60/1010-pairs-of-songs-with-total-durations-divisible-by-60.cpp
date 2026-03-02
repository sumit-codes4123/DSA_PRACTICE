class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int map[60]={}, cnt=0;
        for(auto x:time){
            int t=x%60;
            int y=(60-t)%60;
            cnt+=map[y];
            map[t]++;

        }return cnt;
    }
};