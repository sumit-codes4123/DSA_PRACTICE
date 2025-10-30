class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();
        for (int i = 0; i < k; i++) {
            int richidx = 0;
            for (int j = 0; j < n; j++) {
                if (gifts[richidx] < gifts[j]) richidx = j;
            }
            gifts[richidx] = sqrt(gifts[richidx]);
        }
        long long  int RemainingGifts = accumulate(gifts.begin(), gifts.end(), 0LL);
        return RemainingGifts;
    }
};