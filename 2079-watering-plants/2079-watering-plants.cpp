class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n=plants.size();
        int a=capacity;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a<plants[i]){
                cnt+=2*i;
                a=capacity;
            }
            a-=plants[i];
            cnt++;
        }return cnt;
    }
};