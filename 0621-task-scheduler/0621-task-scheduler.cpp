class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char& ch : tasks) {
            freq[ch - 'A']++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                pq.push(freq[i]);
        }
        int t = 0;
        while (!pq.empty()) {
            int c = n + 1;
            vector<int> s;
            int ts = 0;
            while (c-- && !pq.empty()) {
                if (pq.top() > 1) {
                    s.push_back(pq.top() - 1);
                }
                pq.pop();
                ts++;
            }
            for (int& x : s) {
                pq.push(x);
            }
            t += (pq.empty() ? ts : n + 1);
        }
        return t;
    }
};