class Solution {
public:
    double minPrice(vector<int>& p, vector<int>& d) {
        sort(p.begin(),p.end());
        sort(d.begin(),d.end());
        int n=p.size()-1;
        int m=d.size()-1;
        double sum=0;
        while(n>=0&&m>=0){
            double pr=(p[n] * (100 - d[m])) / 100.0;
            sum+=pr;
            n--;
            m--;
        }
        for(int i=n;i>=0;i--){
            sum+=p[i];
        }
        return sum;

    }
};