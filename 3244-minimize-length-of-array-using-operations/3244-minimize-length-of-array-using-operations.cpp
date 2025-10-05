class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
      int cnt=0,mini=*min_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]%mini>0) return 1; 
            if(nums[i]==mini) cnt++; // count mini.
        }
        return (cnt+1)/2;  
    }
};