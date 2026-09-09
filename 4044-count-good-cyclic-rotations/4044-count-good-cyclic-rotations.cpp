class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        long long s1=0, s2=0;
        int j=n/2;
        for(int i=0;i<n/2;i++){
            s1+=nums[i];
            s2+=nums[j++];
        }
        int cnt=0;
        for(int i=0;i<n/2;i++){
            s1+=nums[i+n/2]-nums[i];
            s2+=nums[i]-nums[i+n/2];
            if(s1!=s2)cnt++;
        }return cnt;
    }
};