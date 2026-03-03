class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int map[24]={};
        long long cnt=0;
        for(auto x:hours){
            int t=x%24;
            int y=(24-t)%24;
            cnt+=map[y];
            map[t]++;
        }return cnt;
    }
};