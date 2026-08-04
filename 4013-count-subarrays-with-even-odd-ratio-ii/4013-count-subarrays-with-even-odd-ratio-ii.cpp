class Solution {
private:
    long long total_count = 0;

    // Standard merge function that counts pairs where left_val >= right_val
    void mergeAndCount(vector<long long>& pref, int left, int mid, int right) {
        vector<long long> temp;
        int i = left;
        int j = mid + 1;

        // While both halves have elements
        while (i <= mid && j <= right) {
            // If the element in the left half is greater than or equal to the right half
            if (pref[i] >= pref[j]) {
                // All elements from pref[i] to pref[mid] will also be >= pref[j]
                total_count += (mid - i + 1);
                temp.push_back(pref[j]);
                j++;
            } else {
                temp.push_back(pref[i]);
                i++;
            }
        }

        // Copy remaining elements
        while (i <= mid) temp.push_back(pref[i++]);
        while (j <= right) temp.push_back(pref[j++]);

        // Copy back to original array
        for (int k = 0; k < temp.size(); k++) {
            pref[left + k] = temp[k];
        }
    }

    // Divide the array recursively
    void mergeSort(vector<long long>& pref, int left, int right) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        mergeSort(pref, left, mid);
        mergeSort(pref, mid + 1, right);
        mergeAndCount(pref, left, mid, right);
    }

public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        total_count = 0;

        // 1. Create the transformed prefix sum array using long long
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            long long val = (nums[i] % 2 == 0) ? b : -a;
            pref[i + 1] = pref[i] + val;
        }

        // 2. Use Merge Sort to count all pairs where pref[l] >= pref[r] (l < r)
        mergeSort(pref, 0, n);

        return total_count;
    }
};