class Solution {
public:
    bool isvalid(vector<vector<char>>&b,int r,int c, int k){
        for(int i=0;i<9;i++){
            if(b[r][i]==k)return false;
            if(b[i][c]==k)return false;
        }
        int br=(r/3)*3;
        int bc=(c/3)*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(b[br+i][bc+j]==k)return false;
            }
        }
        return true;
    }
    bool sudoku(vector<vector<char>>&b,int r,int c){
        for(int i=r;i<9;i++){
            int s=(i==r)?c:0;
            for(int j=s;j<9;j++){
                if(b[i][j]=='.'){
                    for(int k='1';k<='9';k++){
                        if(isvalid(b,i,j,k)){
                            b[i][j]=k;
                            if(sudoku(b, i, j)) return true;
                            b[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board,0,0);
    }
};