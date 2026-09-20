class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& in) {
        int n=in.size();
        long long cnt=0;
        priority_queue<int,vector<int>,greater<>>pq;
        sort(in.begin(),in.end());
        pq.push(in[0][1]);
        for(int i=1;i<n;i++){
            while(!pq.empty()&&pq.top()<in[i][0]){
                pq.pop();
            }
            cnt+=pq.size();
            pq.push(in[i][1]);
        }
        return cnt;
    }
};