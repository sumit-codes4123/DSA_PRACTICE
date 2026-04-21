class Solution {
public:
    int minOperations(vector<int>& nums) {
        int a=1;
        int ans=0;
        for(int x:nums){
            if(a!=x){
                a=x;
                ans++;
            }
        }return ans;
    }
};