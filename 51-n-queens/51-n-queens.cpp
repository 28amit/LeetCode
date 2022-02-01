class Solution {
    void solve(int col,vector<vector<string>>&ans,vector<string>&board,int n,vector<int>&left,vector<int>&updig,vector<int>&downdig){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(left[i]==0&&downdig[i+col]==0&&updig[n-1+col-i]==0){
                board[i][col]='Q';
                left[i]=1;
                downdig[i+col]=1;
                updig[n-1+col-i]=1;
                solve(col+1,ans,board,n,left,updig,downdig);
                board[i][col]='.';
                left[i]=0;
                downdig[i+col]=0;
                updig[n-1+col-i]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s(n,'.');
        vector<string>board(n,s);
        vector<int>left(n,0);
        vector<int>updig(2*n-1,0);
        vector<int>downdig(2*n-1,0);
        solve(0,ans,board,n,left,updig,downdig);
        return ans;
    }
};