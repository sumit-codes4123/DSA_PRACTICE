class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int cnt =0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=0;
            int y=0;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0)x++;
                else y++;
                if(y>0&&b * x <= a * y)cnt++;
            }
        }
        return cnt;
    }
};