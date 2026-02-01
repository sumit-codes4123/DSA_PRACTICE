class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mpp1,mpp2;
        vector<vector<int>>ans(2);
        for(auto x:matches){
            mpp1[x[1]]++;
            mpp2[x[0]]++;
        }
        for(auto& it:mpp1){
            if(it.second==1)ans[1].push_back(it.first);
        }
        for(auto& it:mpp2){
            if(mpp1.find(it.first)==mpp1.end())ans[0].push_back(it.first);
        }return ans;
    }
};