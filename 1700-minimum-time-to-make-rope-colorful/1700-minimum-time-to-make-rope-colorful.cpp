class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int mintime=0;
        int maxtime=neededTime[0];
        for(int i=1;i<n;i++){
            if(colors[i]==colors[i-1]){
                mintime+=min(maxtime,neededTime[i]);
                maxtime=max(maxtime,neededTime[i]);
            }else 
            maxtime=neededTime[i];
        }return mintime;
    }
};