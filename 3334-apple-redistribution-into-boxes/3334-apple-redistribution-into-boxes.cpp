class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=0,cnt=0;
        for(int x:apple){
            sum+=x;
        }
        sort(capacity.begin(),capacity.end());
        int m=capacity.size();
        for(int j=m-1;j>=0;j--){
            sum-=capacity[j];
            cnt++;
            if(sum<=0)break;
        } return cnt;
    }
};