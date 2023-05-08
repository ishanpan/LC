class Solution {
public:
    
    int dp[201][201];
    int move(vector<vector<int>>& grid, int i, int j,int m,int n){
        
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        int takeRight = INT_MAX;
        if(i+1<m){
            takeRight = grid[i][j] + move(grid,i+1,j,m,n);
        }
        int takeDown = INT_MAX;
        
        if(j+1<n)
        takeDown = grid[i][j] + move(grid,i,j+1,m,n);
        
        return dp[i][j] = min(takeRight,takeDown);
        
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return move(grid,0,0,m,n);
        
    }
};