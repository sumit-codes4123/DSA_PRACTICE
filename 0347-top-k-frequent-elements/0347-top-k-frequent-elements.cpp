class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        vector<int>res(k);
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        auto comp=[&mpp](int n1,int n2){
            return mpp[n1]>mpp[n2];
        };
        priority_queue<int ,vector<int>,decltype(comp)>heap(comp);
        for (pair<int,int>p:mpp){
            heap.push(p.first);
            if(heap.size()>k)heap.pop();
            
        }
        for(int i=k-1;i>=0;i--){
            res[i]=heap.top();
            heap.pop();
        }return res;
    }
};