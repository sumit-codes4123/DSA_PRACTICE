class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>r[9];
        unordered_set<char>co[9];
        unordered_set<char>b[9];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c=board[i][j];
                if(c=='.')continue;
                int k=(i/3)*3+(j/3);
                if(r[i].count(c)||co[j].count(c)||b[k].count(c))return false;
                r[i].insert(c);
                co[j].insert(c);
                b[k].insert(c);
            }
        }
        return true;
    }
};