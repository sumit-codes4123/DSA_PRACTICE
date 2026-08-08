class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        int n=nums.size();
        map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }
        while(!mp.empty()){
            int f=mp.begin()->first;
            for(int i=f;i<f+k;i++){
                if(!mp.count(i))return false;
                mp[i]--;
                if(mp[i]==0)mp.erase(i);
            }
        } 
        return true;
    }
};