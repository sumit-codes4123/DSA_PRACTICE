class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<int, vector<int>,greater<int>> pq;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pq.push(mat[i][j]);
            }
        }
        // k=n*m-k;
        while(1){
            k--;
            if(k==0)return pq.top();
            pq.pop();
        }
        return -1;
    }
};