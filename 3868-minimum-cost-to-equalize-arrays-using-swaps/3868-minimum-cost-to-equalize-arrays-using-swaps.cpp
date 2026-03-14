class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>freq;
        for(int x:nums1) freq[x]++;
        for(int x:nums2) freq[x]++;
        for(auto&p:freq){
            if(p.second%2==1)return -1;
        }
        unordered_map<int,int>cnt,target;
        int cost=0;
        for(auto &it:freq) cnt[it.first]=it.second/2;
        for(int x:nums1)target[x]++;
        for(auto &p:cnt){
            if(p.second>target[p.first]){
                cost+=p.second-target[p.first];
            }
        }
        return cost;
    }
};