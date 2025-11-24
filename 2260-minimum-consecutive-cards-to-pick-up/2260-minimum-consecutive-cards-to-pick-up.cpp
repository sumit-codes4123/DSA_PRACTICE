class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> lastIndex;
        int mini = INT_MAX;

        for (int i = 0; i < cards.size(); i++) {
            if (lastIndex.find(cards[i]) != lastIndex.end()) {
                mini = min(mini, i - lastIndex[cards[i]] + 1);
            }
            lastIndex[cards[i]] = i;
        }
        return (mini == INT_MAX) ? -1 : mini;
    }
};