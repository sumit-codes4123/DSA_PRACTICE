class Solution {
public:
    int minMoves(vector<int>& nums) {
        int low=INT_MAX;
        int moves=0;
        for(int x:nums){
           low=min(low,x);
        }
        for(int x:nums){
            moves+=x-low;
        }
        return moves;
    }
};