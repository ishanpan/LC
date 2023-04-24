class Solution {
public:
    int dp[201][201];
    int move(vector<vector<int>>& triangle, int i,int j){
        
        if(i>=triangle.size() || j>=triangle[i].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int takeonJ = move(triangle,i+1,j)+triangle[i][j];
        int takeonJP = INT_MAX;
        if(triangle[i].size()>j+1){
             takeonJP = move(triangle,i+1,j+1)+triangle[i][j+1];
        }
       
        
        return dp[i][j] = min(takeonJ,takeonJP);
        
        
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return move(triangle,0,0);
        
        
    }
};