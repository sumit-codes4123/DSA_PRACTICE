class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int prev=0,cnt=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=intervals[prev][1])
            prev=i;
            else{
                if(intervals[prev][1]>=intervals[i][1]){
                    prev=i;
                    cnt++;
                }else cnt++;
            }
        }return cnt;
    }
};