class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mpp;
        int cnt=0;
        for(int num:tasks) mpp[num]++;
        for(auto &it:mpp){
             if(it.second==1) return -1;
            cnt+=(it.second+2)/3;
        }return cnt;
    }
};