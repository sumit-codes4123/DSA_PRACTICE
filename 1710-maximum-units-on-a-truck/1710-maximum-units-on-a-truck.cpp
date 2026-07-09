class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& b, int t) {
        sort(b.begin(), b.end(), cmp);
        int ans=0;
        for(int i=0;i<b.size();i++){
            if(t>=b[i][0]){
                ans+=b[i][0]*b[i][1];
                t-=b[i][0];
            }else{
                ans+=t*b[i][1];
                break;
            }
        }
        return ans;
    }
};