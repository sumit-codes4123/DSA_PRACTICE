class Solution {
public:
    void bt(string &d,int i,string c,vector<string>&res,unordered_map<char,string>&dl){
        if(i==d.size()){
            res.push_back(c);
            return;
        }
        string l=dl.at(d[i]);
        for(char a:l){
            bt(d,i+1,c+a,res,dl);
        }
    }
    vector<string> letterCombinations(string d) {
        vector<string >res;
        if(d.empty())return res;
        unordered_map<char,string>dl={
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        bt(d,0,"",res,dl);
        return res;
    }
};