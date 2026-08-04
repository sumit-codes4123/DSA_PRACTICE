class Solution {
public:
    int binary(vector<long long>&s,long long k){
        int low=0;
        int high=s.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(s[mid]<=k){
                low=mid+1;
            }
            else high=mid-1;
        }
        return low;
    }
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=shifts.size();
        int m=tasks.size();
        vector<int>ans(n,0);
        vector<long long >pre(m,0);
        pre[0]=tasks[0];
        for(int i=1;i<m;i++){
            pre[i]=(long long)tasks[i]+pre[i-1];
        }

        long long ttt=pre[m-1];
        long long aw=0;
        for(int i=0;i<n;i++){
            aw+=shifts[i];
            if(aw>=ttt){
                ans[i]=0;
                aw=0;
            }
            else{
                int j=binary(pre,aw);
                ans[i]=m-j;
            }
        }
        return ans;
    }
};