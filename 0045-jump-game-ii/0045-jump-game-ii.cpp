class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, jump = 0, n = nums.size();
        while (r < n - 1) {
            int far=0;
            for(int i=l;i<=r;i++){
                far=max(i+nums[i],far);
            }
            l=r+1;
            r=far;
            jump=jump+1;
        }return jump;
    }
};