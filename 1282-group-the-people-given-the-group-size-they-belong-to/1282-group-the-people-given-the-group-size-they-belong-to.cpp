class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        map<int, vector<int>> mpp;
        int n = arr.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            mpp[arr[i]].push_back(i);
            if (mpp[arr[i]].size() == arr[i]) {
                ans.push_back(mpp[arr[i]]);
                mpp[arr[i]].clear();
            }
        }
        return ans;
    }
};