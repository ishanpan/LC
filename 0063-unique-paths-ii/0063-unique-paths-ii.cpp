class Solution {
public:
    
    int dp[101][101];
    
    int move(vector<vector<int>>& obstacleGrid, int i,int j,int m,int n){
 
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(i==m-1 && j==n-1 && obstacleGrid[i][j]==1){
            return 0;
        }
        if(i==m-1 && j==n-1 && obstacleGrid[i][j]==0){
            return 1;
        }
        

        int paths = 0;
        if(i+1<m && obstacleGrid[i+1][j]!= 1){
            paths+=move(obstacleGrid,i+1,j,m,n);
        }
        if(j+1<n && obstacleGrid[i][j+1]!= 1){
            paths+=move(obstacleGrid,i,j+1,m,n);
        }
        
        return dp[i][j] = paths;
        
        
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        return move(obstacleGrid,0,0,m,n);
    }
};