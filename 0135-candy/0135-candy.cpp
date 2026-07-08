class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        if(n==0)return 0;
        int sum = 1, i = 1;
        while (i < n) {
            if(r[i]==r[i-1]){
                sum++;
                i++;
                continue;
            }
            int peak=1;
            while(i<n&&r[i]>r[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n&&r[i]<r[i-1]){
                sum+=down;
                down++;
                i++;
            }
            if(down>peak){
                sum+=(down-peak);
            }
        }return sum;
    }
};