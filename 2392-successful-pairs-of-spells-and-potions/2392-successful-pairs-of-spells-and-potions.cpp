class Solution {
public:
    int check(vector<int>& potions, long long strength, long long success) {
        int low = 0, high = potions.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
           if ((long long)potions[mid] * strength >= success){
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int ind=check(potions,spells[i],success);
            ans[i] = (ind >= m ? 0 : m - ind);
        }return ans;
    }
};