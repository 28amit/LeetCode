class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char n='1';n<='9';n++){
                        if(check(board,i,j,n)){
                            board[i][j]=n;
                            if(solve(board))
                                return 1;
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }
    bool check(vector<vector<char>>& board,int r,int c, int n){
        for(int i=0;i<9;i++){
            if(board[r][i]==n)
                return false;
            if(board[i][c]==n)
                return 0;
            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==n)
                return 0;
        }
        return 1;
    }
};