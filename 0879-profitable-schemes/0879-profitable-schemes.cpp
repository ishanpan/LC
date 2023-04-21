class Solution {
public:
    int dp[101][101][101];
    int modV = 1000000007;
    int noOfWays(int n, int i, vector<int>& group, vector<int>& profit, int s,int profitReq){
        
        if(n<0){
            return 0;
        }
        
        if(i==s){
            if(profitReq<=0){
                return 1;
                
            }
            else{
                return 0;
            }
        }
        
        if(profitReq<0) profitReq=0;
        if(dp[i][n][profitReq]!=-1){
            return dp[i][n][profitReq];
        }
    
        int notTake = noOfWays(n,i+1,group,profit,s,profitReq);

         int take = noOfWays(n-group[i],i+1,group,profit,s,profitReq-profit[i]);
      
        return dp[i][n][profitReq] =  (notTake+take)%modV;
        
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return noOfWays(n,0,group,profit,profit.size(),minProfit);
    }
};