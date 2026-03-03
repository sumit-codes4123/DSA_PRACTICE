class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>mpp;
        int cnt=0;
        for(int x:arr){
            int t=((x%k)+k)%k;
            int y=(k-t)%k;
            if(mpp[y]>0){
                mpp[y]--;
                cnt++;
            }
            else mpp[t]++;
        }return cnt==arr.size()/2;
    }
};