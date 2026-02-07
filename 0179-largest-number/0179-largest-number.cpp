class Solution {
public: 
    bool static compare(int a,int b){ 
       string s1 = to_string(a);   //stoi()
       string s2 = to_string(b);
       return s1+s2>s2+s1;   
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare); 
        string ans="";  
        for(int i=0;i<nums.size();i++){
            if (nums[0] == 0) return "0";
            ans+=to_string(nums[i]); 
        }
        return ans;
    }
};