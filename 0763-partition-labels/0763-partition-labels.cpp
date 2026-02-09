class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>mpp;
        for( int i=0;i<s.size();i++)mpp[s[i]]=i;
        vector<int>ans;
        int maxi=0,last=-1;
        for(int i=0;i<s.size();i++){
            maxi=max(maxi,mpp[s[i]]);
            if(maxi==i){
                ans.push_back(maxi-last);
                last=maxi;
            }
        }return ans;
    }
};