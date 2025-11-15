class Solution {
public:
    vector<int> findNSE(vector<int>&ar){
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
    vector<int> findPSE(vector<int>&ar){
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
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);

        long long total = 0;
        long long mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total = (total + (left * right % mod) * arr[i] % mod) % mod;
        }
        return total;
    }
};