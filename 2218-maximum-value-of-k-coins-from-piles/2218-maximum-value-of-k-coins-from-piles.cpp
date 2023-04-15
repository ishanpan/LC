class Solution {
public:
    
    int dp[1001][2001];
    int maxV(vector<vector<int>>& piles, int k,int pileNo){
        if(k==0 || pileNo<0){
            return 0;
        }
        
        if(dp[pileNo][k]!=-1){
            return dp[pileNo][k];
        }
        int currPileSize = piles[pileNo].size(); 
        int dontTakeAnyPile = maxV(piles,k,pileNo-1);
        int minSize = min(currPileSize,k);
        
        //now take some from the pile
        int maxx = dontTakeAnyPile;
        int takeOne = 0;
        for(int i=0;i<minSize;i++){
            takeOne += piles[pileNo][i];
            
            int takeFromNewPile = maxV(piles,k-i-1,pileNo-1);
            
            maxx=max(maxx,takeOne+takeFromNewPile);
            
        }
        return dp[pileNo][k] = maxx;
        
    }
    
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return maxV(piles,k,piles.size()-1);
    }
};