class Solution {
public:
    int n,m;
    int solve(vector<vector<char>>& grid,int i,int j){
        if(i<0||i>=n||j<0||j>=m||grid[i][j]=='0')
            return 0;
        grid[i][j]='0';
        solve(grid,i,j+1);
        solve(grid,i,j-1);
        solve(grid,i-1,j);
        solve(grid,i+1,j);
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)
            return 0;
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans+=solve(grid,i,j);    
                }
            }
        }
        return ans;
    }
};