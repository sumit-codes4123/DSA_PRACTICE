class Solution {
public:
    int countElements(vector<int>& nums, int k) {
       int n=nums.size();
        if(k==0) return n;
        if(k>=n) return 0;
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int j=upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
            if(n-j>=k) cnt++;
        }return cnt;
    }
};