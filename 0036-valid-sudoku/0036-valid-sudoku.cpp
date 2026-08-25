class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool r[9][10]={false};
        bool co[9][10]={false};
        bool b[9][10]={false};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c=board[i][j];
                if(c=='.')continue;
                int num=c-'0';
                int k=(i/3)*3+(j/3);
                if(r[i][num]||co[j][num]||b[k][num])return false;
                r[i][num]=true;
                co[j][num]=true;
                b[k][num]=true;
            }
        }
        return true;
    }
};