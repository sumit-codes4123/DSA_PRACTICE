class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> a;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot)
                nums[j++] = nums[i];
            else {
                a.push_back(nums[i]);
            }
        }
        n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] == pivot) {
                nums[j++] = a[i];
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]>pivot)nums[j++]=a[i];
        }
        return nums;
    }
};