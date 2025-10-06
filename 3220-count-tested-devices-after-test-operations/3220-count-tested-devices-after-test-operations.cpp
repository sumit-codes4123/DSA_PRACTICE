class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n=batteryPercentages.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(batteryPercentages[i]>0){
                cnt++;
                for(int j=i;j<n;j++){
                    batteryPercentages[j] = max(0, batteryPercentages[j] - 1);
                }
            }
        }return cnt;
    }
};