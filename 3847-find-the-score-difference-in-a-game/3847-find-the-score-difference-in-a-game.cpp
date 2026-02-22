class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int p1=0,p2=0;
        bool first=true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0) first=!first;
            if(i%6==5) first=!first;
            if(first) p1+=nums[i];
            else p2+=nums[i];
        }return p1-p2;
    }
};