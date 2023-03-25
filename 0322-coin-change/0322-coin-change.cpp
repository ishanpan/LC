class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int t[n+1][amount+1];
        
        for(int i=0;i<n+1;i++){
            t[i][0] = 0;
        }
        for(int i=1;i<amount+1;i++){
            t[0][i] = 10e8;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1]<=j){
                    t[i][j] = min(t[i-1][j],1+t[i][j-coins[i-1]]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        if(t[n][amount]==10e8){
            return -1;
        }
        return t[n][amount];
        
    }
};