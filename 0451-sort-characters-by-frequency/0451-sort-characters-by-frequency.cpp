class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        vector<pair<char,int>>v;
        for(auto &t:mp){
            v.push_back(t);
        }
        sort(v.begin(),v.end(),[](
            auto &a,auto &b){
                return a.second>b.second;
            }
        );
        string t="";
        for(auto it:v){
            t += string(it.second, it.first);
        }
        return  t;
    }
};