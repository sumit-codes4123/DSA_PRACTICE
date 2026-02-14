class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int>mpp;
        int cnt=0;
        for(int i=0;i<words.size();i++){
            if(words[i].size()>=k) mpp[words[i].substr(0,k)]++;
        }
        for(auto & it:mpp){
            if(it.second>=2)cnt++;
        }return cnt;
    }
};