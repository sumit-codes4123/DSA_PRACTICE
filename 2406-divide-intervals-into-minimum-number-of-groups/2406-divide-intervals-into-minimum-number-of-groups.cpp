class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int>s,e;
        for(int i=0;i<n;i++){
            s.push_back(intervals[i][0]);
            e.push_back(intervals[i][1]);
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        int cnt=0,maxcnt=0;
        int i=0,j=0;
        while(i<n){
            if(s[i]<=e[j]){
                cnt++;
                i++;
            }else{
                cnt--;
                j++;
            }
            maxcnt=max(maxcnt,cnt);
        }return maxcnt;
    }
};