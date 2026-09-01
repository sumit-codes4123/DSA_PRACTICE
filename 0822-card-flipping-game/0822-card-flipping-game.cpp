class Solution {
public:
    int flipgame(vector<int>& f, vector<int>& b) {
        unordered_set<int>st;
    
        for(int i=0;i<f.size();i++){
            if(f[i]==b[i])st.insert(f[i]);
        }
        int ans=INT_MAX;
        for(int i=0;i<f.size();i++){
            if(st.find(f[i])==st.end()){
                ans=min(ans,f[i]);
                
            }
            if(st.find(b[i])==st.end()){
                ans=min(ans,b[i]);
            }
        }
        return ans==INT_MAX?0:ans;
    }
};