class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<bool> visited(101,false);
        int ans = 0;
        for(auto x : nums){
            for(int i = x[0]; i<=x[1]; i++){
                if(visited[i] == false){
                    visited[i] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};