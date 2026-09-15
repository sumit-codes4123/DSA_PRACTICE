class Solution {
public:
    vector<string>res;
    void bt(int i,string path,string &num,int t,long long currval,long long pval){
        if(i==num.size()){
            if(t==currval)
              res.push_back(path);
            return;
        }
        for(int j=i;j<num.size();j++){
            if(j>i&&num[i]=='0')break;
            string part=num.substr(i,j-i+1);
            long long val=stoll(part);
            if(i==0){
                bt(j+1,part,num,t,val,val);
            }
            else{      
                bt(j+1,path+"+"+part,num,t,currval+val,val);
                bt(j+1,path+"-"+part,num,t,currval-val,-val);
                bt(j+1,path+"*"+part,num,t,currval-pval+(pval*val),(pval*val));
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        res.clear();
        if(num.size()==0)return res;
        bt(0,"",num,target,0,0);
        return res;
    }
};