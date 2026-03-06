class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int maxi=nums[0],mini=nums[nums.size()-1],s=-1,e=-1;
        for(int i=1;i<nums.size();i++){
            if(maxi<=nums[i]) maxi=nums[i];
            else e=i;
        }
        for(int i=nums.size()-2;i>=0;i--){
            if(mini>=nums[i])mini=nums[i];
            else s=i;
        }
        if(s==-1)return 0;
        return e-s+1;
    }
};