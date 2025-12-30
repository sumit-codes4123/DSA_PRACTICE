class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max=0;
       vector<int>ans(2,0);
        for(int i=0;i<mat.size();i++){
            int c=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1) c++;
            }
            if(c>max){
                max=c;
                ans[0]=i;
            }
        }
        ans[1]=max;
        return ans;
    }
};