class Solution {
public:
    int dp[1001];
    int climb(vector<int>& cost, int i,int n){
        if(i>=n){
            return 0;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        int jump1 = climb(cost,i+1,n)+cost[i];
        
        int jump2 = climb(cost,i+2,n)+cost[i];
        
        return dp[i] = min(jump1,jump2);

    }
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        memset(dp,-1,sizeof(dp));
        int ans1 = climb(cost,0,cost.size());
        
        memset(dp,-1,sizeof(dp));
        int ans2 = climb(cost,1,cost.size());
        
        return min(ans1,ans2);
        
    }
};