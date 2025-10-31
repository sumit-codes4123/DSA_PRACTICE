class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        while(k>0){
            int mxm=0,i=0;
            for(auto & it:mpp){
                if(it.second>mxm){
                    mxm=it.second;
                    i=it.first;
                }
            }res.push_back(i);
            mpp.erase(i);
            k--;
        }return res;
    }
};