class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int total=0;
        for(int i:nums) total+=i;
        if(total==x)return n;
        int sum=0,i=0,j=0,len=0;
        int need=total-x;
        while(j<n){
            sum+=nums[j];
            while(sum>need&&i<j){
                sum-=nums[i];
                i++;
            }
            if(sum==need) len=max(len,j-i+1);
            j++;
        }if(len==0)return -1;
        return n-len;
    }
};