class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>result(nums.size()-k+1);
        int s=0,e=0;
        int maxi=0,n=0;
        for(int i=0;i<=nums.size()-k;i++){
            bool iscons=true;
            for(int j=i;j<i+k-1;j++){
                if(nums[j+1]!=nums[j]+1){
                    iscons=false;
                    break;
                }
            }if(iscons) result[i]=nums[i+k-1];
            else result[i]=-1;
        }return result;
    }
};