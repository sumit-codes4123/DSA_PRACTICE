class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>freq;
        int maxi=-1;
        for(int n:arr){
            freq[n]++;
        }for(auto & it: freq){
            if(it.second==it.first)
            maxi=max(maxi,it.first);
        }return maxi;
    }
};