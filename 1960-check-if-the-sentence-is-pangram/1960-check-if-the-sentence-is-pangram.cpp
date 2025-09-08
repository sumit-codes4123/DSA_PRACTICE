class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char,int>mpp;
        for(int i=0;i<sentence.size();i++){
            mpp[sentence[i]]++;
        }if(mpp.size()!=26) return false;
        else return true;
    }
};