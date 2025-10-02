class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       map<int, int>mpp;
        vector<int> res;
        for(int num : nums) {
            mpp[num]++;
        }
        for(int i = 1; i <= nums.size(); i++){
            if(mpp.find(i) == mpp.end())  res.push_back(i); 
          }  return res;   
    }
};