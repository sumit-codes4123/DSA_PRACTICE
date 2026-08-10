class Solution {
public:

    int count(int mid,int m,int n){
        int cnt=0;
        for(int i=1;i<=m;i++){
            cnt+=min(mid/i,n);
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        int low=1,high=m*n;
        int ans=low;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(count(mid,m,n)>=k){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};