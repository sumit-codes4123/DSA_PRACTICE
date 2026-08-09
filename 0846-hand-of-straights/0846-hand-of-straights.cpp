class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        map<int,int>mp;
        for(int x:hand)mp[x]++;
        while(!mp.empty()){
            int a=mp.begin()->first;
            for(int i=a;i<a+k;i++){
                if(!mp.count(i))return false;
                mp[i]--;
                if(mp[i]==0)mp.erase(i);
            }
        }
        
        return true;
    }
};