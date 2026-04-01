class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int t[1001]={0};
        for(int i=0;i<trips.size();i++){
            int p=trips[i][0];
            int f=trips[i][1];
            int d=trips[i][2];
            t[f]+=p;
            t[d]-=p;
        }
        int cnt=0;
        for(int i=0;i<1001;i++){
            cnt+=t[i];
            if(cnt>capacity)return false;
        }
        return true;
    }
};