class Solution {
public:
    int minCost(vector<int>& sp, vector<int>& hp, vector<int>& rc, vector<int>& cc) {
        int r1=sp[0];
        int r2=hp[0];
        int c1=sp[1];
        int c2=hp[1];
        int res=0;
        if(r2>=r1){
            res+=accumulate(rc.begin()+r1+1,rc.begin()+r2+1,0);
        }else{
            res+=accumulate(rc.begin()+r2,rc.begin()+r1,0);
        }
        if(c2>=c1){
            res+=accumulate(cc.begin()+c1+1,cc.begin()+c2+1,0);
        }else{
            res+=accumulate(cc.begin()+c2,cc.begin()+c1,0);
        }return res;
    }
};