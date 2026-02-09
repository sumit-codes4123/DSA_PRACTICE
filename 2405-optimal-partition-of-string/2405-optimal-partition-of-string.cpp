class Solution {
public:
    int partitionString(string s) {
       map<char,bool>mpp;
       
        int maxi=0;
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])!=mpp.end()){
                maxi++;
                mpp.clear();
            }
            mpp[s[i]]=true;
        }
            return maxi+1;
    
    }
};