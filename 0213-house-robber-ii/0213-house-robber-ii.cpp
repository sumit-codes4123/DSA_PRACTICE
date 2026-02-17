class Solution {
public:
    int rob(vector<int>& nums) {
        int max1=0,max2=0;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n-1;i++){
            int c=max(max1,max2+nums[i]);
            max2=max1;
            max1=c;
        }
        int maxi=max1;
        max1=0,max2=0;
        for(int i=1;i<n;i++){
            int c=max(max1,max2+nums[i]);
            max2=max1;
            max1=c;
        }

        return max(maxi,max1);
    }
};