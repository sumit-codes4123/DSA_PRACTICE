class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
         vector<int> sormadexin = nums;  

        int maxVal = *max_element(sormadexin.begin(), sormadexin.end());
        int minVal = *min_element(sormadexin.begin(), sormadexin.end());

        long long diff = maxVal - minVal;
        return diff * 1LL * k; 
    }
};