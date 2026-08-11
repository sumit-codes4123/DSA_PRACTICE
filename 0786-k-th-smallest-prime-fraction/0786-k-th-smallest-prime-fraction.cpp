class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<pair<double,pair<int,int>>>pq;

        for(int i=0;i<n;i++){
            pq.push({-1.0*arr[i]/arr.back(),{i,n-1}});
        }
        while(--k){
            pair<int,int>cur=pq.top().second;
            pq.pop();
            cur.second--;
            pq.push({-1.0*arr[cur.first]/arr[cur.second],{cur.first,cur.second}});
        }
        pair<int,int>res=pq.top().second;
        return {arr[res.first],arr[res.second]};
    }
};