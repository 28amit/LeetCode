class Solution {
public:
    int n,m;
    int solve(vector<vector<int>>& grid,int i,int j){
        if(i<0||i>=n||j<0||j>=m||!grid[i][j])
            return 0;
        grid[i][j]=0;
        return 1+solve(grid,i-1,j)+solve(grid,i,j+1)+solve(grid,i+1,j)+solve(grid,i,j-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    ans=max(ans,solve(grid,i,j));
            }
        }
        return ans;
    }
};