class Solution {
public:
    vector<int>NSE(vector<int>&ar){
        int n=ar.size();
        vector<int>ns(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&ar[st.top()]>=ar[i]){
                st.pop();
            }
            ns[i]=st.empty()?n:st.top();
            st.push(i);
        }return ns;
    }
    vector<int>PSEE(vector<int>&ar){
        int n=ar.size();
        vector<int>ps(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&ar[st.top()]>ar[i]){
                st.pop();
            }
            ps[i]=st.empty()?-1:st.top();
            st.push(i);
        }return ps;
    }
    long long sumMin(vector<int>& nums) {
        int n = nums.size();
        vector<int> nextSm = NSE(nums);
        vector<int> prevSm = PSEE(nums);
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - prevSm[i];
            long long right = nextSm[i] - i;
            total += left * right * (long long)nums[i];
        }
        return total;
    }
    vector<int>NGE(vector<int>& nums) {
        int n = nums.size();
        vector<int> nxt(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            nxt[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nxt;
    }

    vector<int>PGEE(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n, -1);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop(); 
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prev;
    }

    long long sumMax(vector<int>& nums) {
        int n = nums.size();
        vector<int> nextGr = NGE(nums);
        vector<int> prevGr = PGEE(nums);
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - prevGr[i];
            long long right = nextGr[i] - i;
            total += left * right * (long long)nums[i];
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumMax(nums) - sumMin(nums);
    }
};