class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double maxi=sum/k;
        int j=0;
        for(int i=k;i<nums.size();i++){
            sum=sum-nums[j++]+nums[i];
            double x=sum/k;
            maxi=max(maxi,x);
        }
        return maxi;
    }
};