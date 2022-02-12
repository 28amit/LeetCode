class Solution {
public:
    int n,m;
    bool dfs(vector<vector<char>>& board, string word,int i,int j,int count){
        if(count==word.size())
            return 1;
        if(i<0||i>=n||j<0||j>=m||board[i][j]!=word[count])
            return 0;
        char tmp=board[i][j];
        board[i][j]='*';
        bool ans=dfs(board,word,i-1,j,count+1)||dfs(board,word,i,j+1,count+1)||dfs(board,word,i+1,j,count+1)||dfs(board,word,i,j-1,count+1);
        board[i][j]=tmp;
        return ans;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]&&dfs(board,word,i,j,0))
                    return 1;
            }
        }
        return 0;
    }
};