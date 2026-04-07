class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int even=0,odd=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0)even+=nums[i];
            else odd+=nums[i];
        }
        int leven=0,lodd=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0) even-=nums[i];
            else odd-=nums[i];
            if(lodd+even==leven+odd)ans++;
            if(i%2==0)leven+=nums[i];
            else lodd+=nums[i];
        }return ans;
    }
};