class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(),score.end(),[&](vector<int>&x,vector<int>&y){
            return x[k]>y[k];
        });
        return score;
    }
};