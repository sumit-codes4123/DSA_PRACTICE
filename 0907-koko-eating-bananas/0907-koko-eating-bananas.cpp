class Solution {
public:
    int findmax(vector<int>& piles) {
        int ans = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            ans = max(ans, piles[i]);
        }
        return ans;
    }

    long long calculatehours(vector<int>& piles, int hourly) {
        long long totalh = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalh += (piles[i] + hourly - 1) / hourly;
        }
        return totalh;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findmax(piles);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalh = calculatehours(piles, mid);  // Use long long here
            if (totalh <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};