class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int i = 0;
        int j = plants.size() - 1;
        int a = capacityA;
        int b = capacityB;
        int cnt = 0;
        while (i < j) {
            if (a < plants[i]) {
                cnt++;
                a = capacityA;
            }
            a = a - plants[i];
            i++;
            if (b < plants[j]) {
                cnt++;
                b = capacityB;
            }
            b = b - plants[j];
            j--;
        }
        if (i == j){
            if (max(a, b) < plants[i])
                cnt++;
        }    
        return cnt;
    }
};